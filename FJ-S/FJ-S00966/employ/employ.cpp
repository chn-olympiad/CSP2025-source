#include<bits/stdc++.h>
using namespace std;
int a[10000000];
char s[10000000];
int b[10000000];
int k[10000000];
int n,m,ans;
int check(int mm)
{int g=0,mg=0;
	for(int i=1;i<=n;i++)
	{
		if(k[i]>mg)
		{
			if(s[i]=='1')
			{
				g++;
			}
			else
			{
				mg++;
			}
		}
		else
		{
			mg++;
		}
		
	}
	if(g>=mm)
	{
		return 1;
	}
	
	return 0;
}
void dfs(int st)
{
	if(st>n)
	{
		int v=check(m);
		if(v==1)
		{
			ans++;
		}
		return ;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(b[i]==0)
			{
				b[i]=1;
				k[i]=a[i];
				dfs(st+1);
				b[i]--;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m; 
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
}

