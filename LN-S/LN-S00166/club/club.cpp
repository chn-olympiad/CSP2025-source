#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,a[200000][5];
inline void dfs(long long m,long long c,long long v,long long m1,long long m2,long long m3)
{
    if(m>n){//if(m1=n/2){
        ans=max(ans,v);
        return;
    }
    if(m1<n/2) dfs(m+1,1,v+a[m][c],m1+1,m2,m3);
    if(m2<n/2) dfs(m+1,2,v+a[m][c],m1,m2+1,m3);
    if(m3<n/2) dfs(m+1,3,v+a[m][c],m1,m2,m3+1);

}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    a[0][0]=0;
    for(int i=1;i<=t;i++){
        ans=-1;
        scanf("%lld",&n);
        for(int j=1;j<=n;j++) scanf("%lld%lld%lld",&a[j][1],&a[j][2],&a[j][3]);
        //if(i==1||i==3) continue;
        dfs(0,0,0,0,0,0);
        printf("%lld\n",ans);
    }
    return 0;
}
