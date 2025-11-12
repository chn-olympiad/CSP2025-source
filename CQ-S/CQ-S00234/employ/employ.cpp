#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int c[510];
int vis[510];
int n,m;
string s;
int sum1=0; 
void bfs(int sum,int up,int day)
{
	if(day>n)
	{
		if(up>=m) 
		{
			sum1=(sum1+1)%mod;
		}
		return ;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			if(sum<c[i])
			{
				if(s[day-1]=='0') 
				{
					vis[i]=1;
					bfs(++sum,up,++day);
					vis[i]=0;
				}	
				if(s[day-1]=='1') 
				{
					vis[i]=1;
					bfs(sum,++up,++day);
					vis[i]=0;
				}
			}
			else if(sum>=c[i]) 
			{
				vis[i]=1;
				bfs(++sum,up,++day);
				vis[i]=0;
			}
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		vis[i]=1;
		bfs(0,0,1);
		vis[510]={0};
	}
	cout<<sum1%mod;
	return 0;
}

