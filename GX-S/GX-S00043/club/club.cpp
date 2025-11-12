#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<algorithm>
#include<cstring>
#include<map>
#define ll long long 
using namespace std;
void read(ll &x)
{
	x=0;
	bool meg=0;
	char ch=0;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			meg=1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	if(meg==1)
		x=-x;
	return ;
}
void write(ll x)
{
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	if(x>=10) write(x/10),putchar(x%10+'0');
}
ll t,n,m;
ll a[100001][4],ans;
ll b[4];
void dfs(int x,int y)
{
	if(x>n)
	{
		if(y>ans)
			ans=y;
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		if(b[i]<m)
		{
			b[i]++;
			dfs(x+1,y+a[x][i]);
			b[i]--;
		}
		
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(t);
	for(int i=1;i<=t;i++)
	{
		read(n);
		for(int j=1;j<=n;j++)
			for(int k=1;k<=3;k++)
				read(a[j][k]);
		ans=0;
		memset(b,0,sizeof(b));
		m=n/2;
		dfs(1,0);
		write(ans);
		putchar('\n');
	}
	return 0;
}

