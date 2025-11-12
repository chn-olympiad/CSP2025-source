#include<bits/stdc++.h>
using namespace std;
int n=0,m=0;
char sc[600]={};
int s[600]={};
int c[600]={};
long long  ans=0;
int giveup=0;
int duilie[600]={};
int ju[600]={};
int cnt=0;
bool check()
{
	int luqu=0;
	giveup=0;
	for(int i=1;i<=n;i++)
	{
		//cout<<duilie[i]<<" ";
		if(c[duilie[i]]>giveup)
		{
			if(s[i])
			{
				luqu++;
				//cout<<"@";
			}
			else
			{
				giveup++;
			}
		}
		else
		{
			giveup++;
		}
	}
	//cout<<"\n";
	if(luqu>=m)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void dfs(int depth)//di depth hao kao sheng
{
	if(depth>n)
	{
		if(check())
		{
			ans++;
		}
		return;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(ju[i]==0)
			{
				ju[i]=1;
				duilie[depth]=i;			
				dfs(depth+1);			
				ju[i]=0;
				duilie[depth]=0;
			}
		}			
	}	
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>sc[i];
		if(sc[i]=='1')
		{
			s[i]=1;
		}
		if(sc[i]=='0')
		{
			s[i]=0;		
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	/*for(int i=1;i<=n;i++)
	{
		cout<<s[i]<<" ";
	}*/
	dfs(1);
	cout<<ans%998244353;
	return 0;
}
