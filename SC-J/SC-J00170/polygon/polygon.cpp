#include<bits/stdc++.h>
using namespace std;
struct node
{
	int cnt;
	bool vis[45];
	inline bool operator < (const node &x)const
	{
		return x.cnt<cnt;
	}
};
int n;
int a[5010];
int ans;
inline void read(int &x)
{
	int f=1;
	char c;
	c=getchar();
	if(c=='-')f=-1;
	else x=c-'0';
	c=getchar();
	while(c>='0'&&c<='9')
	{
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	x*=f;
}
inline int dfs(node now)
{
	int ans=0;
	if(now.cnt>=3)
	{
		int maxn=-1;
		int sum=0;
		for(int i=1;i<=n;++i)
		{
			if(!now.vis[i])continue;
			sum+=a[i];
			maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn)++ans;
	}
	return ans;
}
bool tmp1[5010];
int main(void)
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	read(n);
	for(int i=1;i<=n;++i)read(a[i]),tmp1[i]=1;
	node tmp;
	for(int i=0;i<=n-2;++i)
	{
		for(int j=1;j<=i;++j)tmp1[j]=0;
		do
		{
			for(int j=1;j<=n;++j)tmp.vis[j]=tmp1[j];
//			cout << '\n';
			tmp.cnt=(n-i+1);
			ans+=dfs(tmp);
		}while(next_permutation(tmp1+1,tmp1+n+1));
		for(int j=1;j<=n;++j)tmp1[i]=1;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}