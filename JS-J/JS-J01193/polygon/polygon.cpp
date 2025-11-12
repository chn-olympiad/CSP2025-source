#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l);(i)<=(r);++(i))
#define rep1(i,l,r) for(int i=(l);(i)<(r);++(i))
#define per(i,l,r) for(int i=(l);i>=(r);--i)
#define il inline
#define cst const
#define csti const int
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
#define eb emplace_back
#define int long long
#define LLL

#ifdef LLL
csti inf=0x3f3f3f3f3f3f3f3fll;
#else
csti inf=0x3f3f3f3f;
#endif // LLL

csti N=5e3+7,mod=998244353;

il int min(csti x,csti y){
    return x<y?x:y;
}

int n,k,a[N],f[N][N];
signed main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    rep(i,1,n){
        cin>>a[i];
    }sort(a+1,a+n+1);
    f[1][a[1]]++;
    rep(i,2,n){
        int now=-a[i];
        csti i1=i-1;
        rep(jj,1,10005){
            ++now;
            csti j=min(5001ll,jj);
            if(jj<=5002)f[i][j]+=f[i1][j];
            if(j>=a[i])f[i][j]+=f[i1][now];
            //f[i][j]+=f[i][j-1];
            f[i][j]%=mod;

            //cout<<i<<' '<<j<<' '<<f[i][j]<<' '<<jj<<"  "<<jj-a[i]<<" "<<f[i-1][min(501ll,jj-a[i])]<<'\n';
        if(now==5000)break;}f[i][a[i]]++;
    }int ans=0;
    per(i,n,1){
        rep(j,a[i]+1,5001)ans+=f[i-1][j];//,cout<<i-1<<' '<<j<<' '<<f[i-1][j]<<"  onm\n";
        ans%=mod;
        //cout<<ans<<' '<<i<<' '<<a[i]<<'\n';
    }cout<<ans;
    return 0;
}
