#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans,s[5005];
bool cmp(long long x,long long y)
{
	return x>y;
}
void dfs(long long step,long long k,long long cnt,long long side)
{
	if(s[step]+cnt<=k || n-step+1+side<3)return;
	if(step>n){
		if(side>=3 && cnt>k){
			ans++;
		}
		return;
	}
	dfs(step+1,k,cnt+a[step],side+1);
	dfs(step+1,k,cnt,side);
	
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i];
	}
	for(long long i=n;i>=1;i--){
		s[i]+=s[i+1];
	}
	sort(a+1,a+n+1,cmp);
	for(long long i=1;i<=n-2;i++){
		dfs(i+1,a[i],0,1);
	}
	cout<<ans%998244353;
	return 0;
}
