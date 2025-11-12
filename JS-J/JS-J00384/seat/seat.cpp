#include <bits/stdc++.h>
using namespace std;
int n,m,num,a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int nm=n*m;
    for(int i=1;i<=nm;i++)
        cin>>a[i];
    num=a[1];
    sort(a+1,a+nm+1,cmp);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[(i-1)*n+j]==num){
                cout<<i<<' ';
                if(i%2==1)
                    cout<<j<<'\n';
                else
                    cout<<n-j+1<<'\n';
                break;
            }
    return 0;
}
