#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL d[10][10]={{1,0},{0,1},{-1,0},{0,1}};
LL n,m,ans;
LL a[100+10];
LL id=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    id=a[1];
    sort(a+1,a+n*m+1);
    reverse(a+1,a+n*m+1);
    //for(int i=1;i<=n*m;i++){
    //    cout<<a[i]<<" ";
    //}
    //cout<<endl;
    LL x=1,y=1;
    LL pos=0;
    while(1){
        ans++;
        if(a[ans]==id){
            cout<<y<<" "<<x;
            return 0;
        }
        //cout<<x<<" "<<y<<" "<<a[ans]<<endl;
        x+=d[pos][0];
        y+=d[pos][1];
        //cout<<x<<" "<<y<<endl;
        if(x==n||x==1){
            pos++;
            pos%=4;
        }
    }
    return 0;
}
