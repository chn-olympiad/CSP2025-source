#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int n,t,val[maxn][5],num[5],dp[maxn],ans;
int m;
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	 } 
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
 } 
void write(int x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	x<10?putchar(x|48):(write(x/10),putchar(x%10|48));
}
void dfs(int nw,int sum)
{
	if(nw==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(num[i]==m)continue;
		num[i]++;
		dfs(nw+1,sum+val[nw][i]);
		num[i]--;
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		m=n>>1;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			val[i][1]=read();
			val[i][2]=read();
			val[i][3]=read();
		}
		dfs(1,0); 
		write(ans);
		putchar('\n');
	}
	return 0;
}