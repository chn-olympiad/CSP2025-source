#include <bits/stdc++.h>
using namespace std;
#define int long long
const int p=998244353;
int n,m,ans,c[505],fac[505];
string s;
bool is[505];
int t[505];
void dfs(int dep,int sum){
	if(sum>n-m) return;
	if(sum+n-dep+1<=n-m){
		ans=(ans+fac[n-dep+1])%p;
		return;
	}
	if(dep==n+1){
		ans=(ans+1)%p;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!is[i]){
			is[i]=true;
			//t[dep]=i;
			//cout<<dep<<" "<<i<<" "<<c[i]<<" "<<sum<<endl;
			if(sum>=c[i]||s[dep]=='0') dfs(dep+1,sum+1);
			else dfs(dep+1,sum);
			is[i]=false;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fac[0]=fac[1]=1;
	scanf("%lld%lld",&n,&m);
	for(int i=2;i<=n;i++){
		fac[i]=(fac[i-1]*i)%p;
	} 
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) scanf("%lld",c+i);
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
