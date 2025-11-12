
#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,m,a[505],b[505];
	string s;
long long ans;
bool vis[505];
void co(int t,int x)
{
	if(t>=n)
	{
		int y=0;
		for(int i=1;i<=n;i++)
		{
		
			if(s[i-1]=='0')y++;
			else if(y>=a[b[i]])y++;
		}
		if(n-y>=m)ans=ans+1;
		ans=ans%N;

	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		b[t+1]=i;
		vis[i]=1;
		co(t+1,i);
		vis[i]=0;
		
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	if(m==n)
	{
		for(char i:s)
		{
			if(i!='1')
			{
				cout<<0;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		vis[i]=1;
		b[1]=i;
		co(1,i);
		vis[i]=0;
	}
	cout<<ans;

	
	return 0;
}//100 38 47
