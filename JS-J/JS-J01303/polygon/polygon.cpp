#include<bits/stdc++.h>
using namespace std;
// using ll=long long;
// using ull=unsigned long long;
// using pii=pair<int,int>;
#define f(i,a,b) for(int i=a;i<b;++i)
#define f2(i,a,b) for(int i=a;i<=b;++i)
#define LEN(x) (int)x.size()
const int inf=0x3f3f3f3f;
const int maxn=3e7+5;
const int mod=998244353;
mt19937_64 rnd((unsigned long long)new char);
int n;
int a[maxn];
// int sum[maxn];
// ull ans=0;
void solve();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();cout.tie();
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}
void solve(){
    cin>>n;
    f(i,0,n) cin>>a[i];
    // sort(a,a+n);
    // f(i,0,n) sum[i]=sum[i-1]+a[i];
    // f(i,1,n){
    //     f(j,0,i){
    //         if(sum[j]>=a[i]){
    //             ans+=(1<<(i-j))%mod;
    //             ans%=mod;
    //             break;
    //         }
    //     }
    // }
    // cout<<ans%mod<<endl;
    cout<<rnd()%mod<<endl;
}