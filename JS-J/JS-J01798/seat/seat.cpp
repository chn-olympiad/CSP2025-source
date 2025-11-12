#include<bits/stdc++.h>
using namespace std;
long long n,m,a[40000],mp[200][200],a1,topn,x,y;
bool cmp(long long __x,long long __y){return __x>__y;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++)cin>>a[i];
    a1=a[0];
    sort(a,a+n*m,cmp);
    for(int i=0;i<m;i++){
        if(i%2==0)for(int j=0;j<n;j++)mp[j][i]=a[topn++];//,cout<<mp[j][i]<<' '<<j<<' '<<i<<endl;
        else for(int j=n-1;j>=0;j--)mp[j][i]=a[topn++];//,cout<<mp[j][i]<<' '<<j<<' '<<i<<endl;
    }
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){if(mp[i][j]==a1)x=i+1,y=j+1;}
    cout<<y<<' '<<x;
    return 0;
}
