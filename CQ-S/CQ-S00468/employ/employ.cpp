#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e2+5,p=998244353;
ll n,m,num;
string s;
int maxn=1;
ll c[N],sum[N];
bool op[N];
ll dfs(ll k,ll z,ll ss){
	if(k>n&&z>=m){
		return 1;
	}
	ll res=0;
	for(int i=1;i<=n;i++){
		if(!op[i]){
			op[i]=1;
			if(ss>=c[i]||s[k-1]=='0') res+=dfs(k+1,z,ss+1);
			else res+=dfs(k+1,z+1,ss);
			op[i]=0;
		}
	}
	return res%p;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		if(s[i]=='0')
			maxn=0;
		num+=(c[i]!=0);
		sum[i]=sum[i-1]+(s[i-1]=='0');
	}
	if(maxn==1){
		if(num>=m){
			ll res=1;
			for(int i=1;i<=n;i++){
				res*=i;
				res%=p;
			}
			cout<<res;
		}
		else
			cout<<0;
	}
	else cout<<dfs(1,0,0)%p;
	return 0;
}
