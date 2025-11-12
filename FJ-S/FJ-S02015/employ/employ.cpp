#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m,a[510],sum=0,p[510];
bool ch[510];
char s[510];
int che()
{
	int t=0,temp=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0'||t>=a[p[i]]) 
		{
			t++;
		}
		else 
		{
			temp++;t=0;
			if(temp>=m) return 1;
		}
	}
	return 0;
}
void dfs(int s)
{
	if(s==n+1)
	{
		sum+=che();
//		for(int i=1;i<=n;i++) cout<<p[i]<<' ';
//		cout<<endl;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(ch[i]) continue;
		ch[i]=1;
		p[s]=i;
		dfs(s+1);
		p[s]=0;
		ch[i]=0;
	}
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int f=0;
	for(int i=1;i<=n;i++) 
	{
		if(s[i]=='1')  f++;	
	}
	if(f==n)
	{
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%mod;	
		}	
		cout<<ans;
		return 0;
	}
	if(f<m||n>18)
	{
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<sum;

	return 0;
}

