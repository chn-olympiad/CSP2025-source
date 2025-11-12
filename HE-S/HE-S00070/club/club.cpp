#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][4];
int k1,k2,k3;
long long ans;
void solve2(int x,long long y){
    if(x==n+1){
        ans=max(ans,y);
        return;
    }
    if(k1>0){
        k1--;
        y+=a[x][1];
        solve2(x+1,y);
        y-=a[x][1];
        k1++;
    }
     if(k2>0){
        k2--;
        y+=a[x][2];
        solve2(x+1,y);
        y-=a[x][2];
        k2++;
    }
    if(k3>0){
        k3--;
        y+=a[x][3];
        solve2(x+1,y);
        y-=a[x][3];
        k3++;
    }
}
void solve(){
    scanf("%d",&n);
    k1=n/2,k2=n/2,k3=n/2;
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
    ans=0;
    solve2(1,0);
    printf("%lld\n",ans);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
        solve();
    return 0;
}
