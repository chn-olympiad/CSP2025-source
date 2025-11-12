#include<bits/stdc++.h>
using namespace std;
int a[5005];
int ans=0;
void dfs(int end,int s,int sum,int du){
	if(s==0){
		if(sum>du){
			ans++;
		}
		return;
	}
	
	if(sum>=du){
		long long ans1=1;
		for(int i=end-s+1;i<=end;i++)ans1*=i;
		for(int i=2;i<=s;i++)ans1/=i;
		ans+=ans1;
		return;
	}
	
	for(int i=end;i>=s;i--){
		dfs(i-1,s-1,sum+a[i],du);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int c=3;c<=n;c++){
		for(int s=c-1;s>=2;s--){
			dfs(c-1,s,0,a[c]);
			ans=(ans+998244353)%998244353;
		}
	}
	cout<<ans;
} 