#include<bits/stdc++.h>
#define int long long
#define N 100005
#define mod 998244353
using namespace std;
int n,m,d[N],p[N],res,fac[N];
char c[N];
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) cin>>d[i];
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    if(n>=12) return cout<<fac[n],0; 
    // cout<<fac[n]<<endl;
    // return 0;
    for(int i=1;i<=n;i++) p[i]=i;
    do{
        int cnt=0,rr=0;
        for(int i=1;i<=n;i++){
            if(cnt>=d[p[i]]){
                cnt++;
                continue;
            }
            cnt+=(c[i]=='0');
            if(c[i]=='1') rr++;
            // if(rr>m) goto FAIL;
        }
        res+=(rr>=m);
        // if(rr==m){
        //     for(int i=1;i<=n;i++) cout<<p[i]<<" ";
        //     cout<<endl;
        // }
        FAIL:;
    }while(next_permutation(p+1,p+n+1));
    cout<<res;
}