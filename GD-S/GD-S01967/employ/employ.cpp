#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10000005;
const int mod=998244353;
ll n,m,c[N],a[N],gcnt,ecnt,ans,cnt;
string s;
int main(){
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m>>s;
    for(ll i=0;i<s.size();++i)if(s[i]=='1')++cnt;
    if(cnt==n){
    	ans=1;
    	for(ll i=2;i<=n;++i)ans=(ans*i)%mod;
    	cout<<ans;
    	return 0;
	}
    for(ll i=1;i<=n;++i)cin>>c[i],a[i]=i;
    do{
        gcnt=ecnt=0;
        for(ll i=1;i<=n;++i){
            if(gcnt>=c[a[i]]){
                ++gcnt;
                continue;
            }
            if(s[i-1]=='1')++ecnt;
            else ++gcnt;
            if(gcnt>n-m)break;
        }
        if(ecnt>=m)ans=(ans+1)%mod;
    } while (next_permutation(a+1,a+n+1));
    cout<<ans;
    return 0;
}
