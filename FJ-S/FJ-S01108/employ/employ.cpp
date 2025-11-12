#include<bits/stdc++.h>
using namespace std;
const int N=1000;
const int mod=998244353;
int n,m;
int c[N];
long long ans=0;
string s;
int dfsn[N];

bool st[N];
int stt[N];
int dfsans=0;
void dfs(int idx,int ly)
{
	if(idx>n)
	{
		if(ly>=m)dfsans++;
//		for(int i=1;i<=n;i++)cout<<dfsn[i]<<" ";
//		cout<<endl<<ly<<endl;
		return;
	}
	for(int i=1;i<=n;i++)
	{
//		cout<<st[i]<<endl; 
		if(st[i]==0)
		{
			st[i]=1;
			dfsn[idx]=i;
			int na=0;
			if(c[i]>stt[idx-1]&&s[idx-1]=='1')na+=1;
			dfs(idx+1,ly+na);
			
			st[i]=0;
		}
	}
	
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		
		if(s[i]=='1')ans++,stt[i+1]=stt[i];
		else stt[i+1]=stt[i]+1;
	}
	
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	
	}
//	for(int i=1;i<=n;i++)
//	{
//		
//		cout<<stt[i]<<endl;
//	}
	if(ans==n)
	{
		for(int i=n-1;i>1;i--)
		{
			ans=(ans*i)%mod;
		}
		cout<<ans;
	}
	if(n<=10)
	{dfs(1,0);
		cout<<dfsans;
	}
	
	return 0;	
} 
