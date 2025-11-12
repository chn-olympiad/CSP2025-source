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
//#define int long long
//#define LLL

#ifdef LLL
csti inf=0x3f3f3f3f3f3f3f3fll;
#else
csti inf=0x3f3f3f3f;
#endif // LLL

csti N=1e6+7,mod=1;

int n,k,a[N],cntt,f[N];
vector<int> g[N];

namespace solve{
    void ss(){
        int ans=0;
        rep(i,1,n){
            if(a[i]==k||a[i-1]==!k&&a[i]==!k&&i>1){
                ans++;
            }
        }cout<<ans;
        exit(0);
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;//cout<<n<<' '<<k<<'\n';
    int mx=0;
    rep(i,1,n){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    if(n>20000&&mx<=1){
        solve::ss();
    }int S=0;
    rep(i,1,n){
        int now=a[i];
        per(j,i-1,0){
            if(now==k){
                f[i]=f[j]+1;break;
            }
            now^=a[j];
        }f[i]=max(f[i],f[i-1]);
        //cout<<f[i]<<'\n';
    }
    cout<<f[n];
//    int now=0,ans=0;
//    per(i,n,1){
//        now^=a[i];
//        if(now==k){
//            ans++,now=0;
//        }
//    }cout<<ans;
    return 0;
}
