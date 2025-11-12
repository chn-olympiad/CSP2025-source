#include<bits/stdc++.h>
using namespace std;
const long long N=5e3+10,mod=998244353;
long long n,maxn,a[N],c,cnt,ans,k,s[N];
void dfs(long long step,long long mx,long long sum)
{
	if(cnt==k){
		if(sum>2*mx)ans++;
		return;
	}
	if(step==n+1)return;
	cnt++;
	dfs(step+1,max(mx,a[step]),sum+a[step]);
	cnt--;
	dfs(step+1,mx,sum);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1,greater<>());
	if(maxn<=1){
		c=n*(n-1)/1/2%mod;
		for(long long i=3;i<=n;i++){
			c=c*(n-i+1)/i%mod;
			ans+=c;
		}
		cout<<ans;
		return 0;
	}
	for(k=3;k<=n;k++)dfs(1,0,0);
	cout<<ans;
	return 0;
}
