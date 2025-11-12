#include<bits/stdc++.h>
using namespace std;
const int N=20,M=110;
int n,m,now=0,fi,c[N][N],a[M];
bool cmp(int a,int b){return a>b;}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>fi;a[1]=fi;
    for(int i=2;i<=n*m;i++)cin>>a[i];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=m;i++){
        if(i%2==1)for(int j=1;j<=n;j++)now++,c[j][i]=a[now];
        if(i%2==0)for(int j=n;j>=1;j--)now++,c[j][i]=a[now];
    }
 //   for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<c[i][j]<<' ';}cout<<'\n';}
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(c[i][j]==fi)cout<<j<<' '<<i;
    return 0;
}
