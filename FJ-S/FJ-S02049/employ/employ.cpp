#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
long long c[505];
long long ns[505];
bool used[505];
long long ans=0;
void dfs(long long cs,long long out){
	long long i;
	if(cs==n+1)
	{
		if(n-out>=m)
		{
			ans++;
		}
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(used[i])
		{
			continue; 
		} 
		used[i]=true;
		ns[cs]=i;
		if(s[cs-1]=='0'||out>=c[i])
		{
			dfs(cs+1,out+1);
		}
		else
		{
			dfs(cs+1,out);
		}
		ns[cs]=0;
		used[i]=false;
	}
}
int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	cin>>s;
	long long i;
	for(i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n!=m)
	{
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		if(s[i-1]=='0'||c[i]==0)
		{
			cout<<0;
			return 0;
		}
	}
	ans=1;
	long long mod=998244353;
	for(i=2;i<=n;i++)
	{
		ans=ans*i%mod;
	}
	cout<<ans;
	
	return 0;
} 
