#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int T,n;
int a[MAXN][4];
int res[MAXN];
int ans;
void dfs(int now,int num1,int num2,int num3,int res)
{
	if(now==n+1)
	{
		ans=max(ans,res);
	}
	if(num1<n/2)
	{
		dfs(now+1,num1+1,num2,num3,res+a[now][1]);
	}
	if(num2<n/2)
	{
		dfs(now+1,num1,num2+1,num3,res+a[now][2]);
	}
	if(num3<n/2)
	{
		dfs(now+1,num1,num2,num3+1,+res+a[now][3]);
	}
}
bool cmp(int a,int b)
{
	return a>b;
}
bool flaga,flagb;
struct node{
	int id,bef,val;
	friend bool operator <(node a,node b){
		return a.val<b.val;
	}
};
struct arr{
	int x,y;
}d[MAXN];
bool cmp5(arr a,arr b){
	return a.x>b.x;
}
priority_queue <node> q;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		flaga=flagb=true;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			d[i].x=a[i][1],d[i].y=a[i][2];
			res[i]=a[i][1];
			if(a[i][2]!=0 || a[i][3]!=0) flaga=false;
		}
		if(n<=30)
		{
			dfs(1,0,0,0,0);
			printf("%d\n",ans);
			continue;
		}
		if(flaga)
		{
			int out=0;
			sort(res+1,res+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				out+=res[i];
			}
			printf("%d\n",out);
			continue;
		}
	}
	return 0;
}
