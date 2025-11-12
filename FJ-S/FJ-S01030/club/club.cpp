#include<bits/stdc++.h>
using namespace std;
const int M = 1e5+5;
struct node{int p,q;}c[M];
int t,n,a[M][4],b[4],ans;
void dfs(int x,int s)
{
	if(x > n)
	{
		ans = max(s,ans);
		return ;
	}
	for(int i=1;i<=3;i++)
		if(b[i] < n/2)
		{
			b[i]++;
			dfs(x+1,s+a[x][i]);
			b[i]--;
		}
}
bool cmp(node x,node y)
{
	return x.q > y.q;
}
int main()
{
	freopen("club.in","r",stdin);	//3,5
	freopen("club.out","w",stdout);
	scanf("%d",&t); 
	while(t--)
	{
		bool o1 = 1, o2 = 1;
		ans = 0;
		memset(a,0,sizeof(a));
		b[1] = b[2] = b[3] = 0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		for(int i=1;i<=n;i++)
		{
			if(a[i][2] != 0) o1 = 0;
			if(a[i][3] != 0) o2 = 0;
		}
		if(o1 && o2)
		{
			int d[M]={0}; 
			for(int i=1;i<=n;i++)
				d[i] = a[i][1];
			sort(d+1,d+n+1);
			reverse(d+1,d+n+1);
			for(int i=1;i<=n/2;i++)
				ans += d[i];
		}
		else if(o2)
		{
			for(int i=1;i<=n;i++)
				c[i].p = i, c[i].q = abs(a[i][1]-a[i][2]);
			sort(c+1,c+1+n,cmp);
			for(int i=1;i<=n;i++)
			{
				int j = c[i].p;
				if((a[j][1]>a[j][2] && b[1] < n/2) || b[2]>=n/2)
				{
					b[1]++;
					ans += a[j][1];
				}
				else b[2]++, ans += a[j][2];
			}
		}
		else dfs(1,0);
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
