#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int a[N];
int n,k;
int r,p,ans,maxn=0;
bool test(int x,int y)
{
	int s[N][30];
	int t;
	for(int i=x;i<=y;i++)
	{
		int j=0;
		s[i][0]=a[i];
		while(s[i][j]!=0)
		{
			s[i][j+1]=s[i][j]/2;
			s[i][j]%=2;
			j++;
		}
	}
	for(int i=x+1;i<=y;i++)
	{
		for(int j=0;j<=25;j++)
		{
			if(s[x][j]!=s[i][j])s[x][j]=1;
			else s[x][j]=0;
		}
	}
	int u=1;
	for(int i=0;i<=25;i++)
	{
		if(s[x][i]==1)t+=u;
		u*=2;
	}
	return t==k;
}
void dfs(int w)
{
	if(w>n)
	{
		ans=max(ans,maxn);
		return;
	}
	for(int i=w+1;i<=n;i++)
	{
		if(test(w,i))
		{
			maxn++;
			dfs(i);
			maxn--;
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)	
	{
		cin>>a[i];
		if(a[i]==0)r++;
		if(a[i]==1)p++;
	}
	if(k==0)
	{
		cout<<r;
		return 0;
	}
	if(k==1)
	{
		cout<<p;
		return 0;
	}
	for(int i=1;i<=n;i++)dfs(i);
	cout<<ans;
	return 0;
}