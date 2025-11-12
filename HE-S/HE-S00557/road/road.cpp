#include<bits/stdc++.h>
using namespace std;
const int N=1e6+20;
const long long mod=1e9+7;
int t;
//记得检查盘，存盘，freopen，删注释，删文件 
int n,m,k,w[N],c[11],a[11][10020];
long long ans;
int ok[10020];
void gmi(long long &x,long long y)
{
	x>y?x=y:0;
}
struct xp{
	int a,b;
	int k;
}lu[N];
void dfs(int x,long long sum,int k)
{
	if(k>=n)
	{
		gmi(ans,sum);
		return ;
	}
	if(x==m+1)
	{
		return ;
	}
	cout<<x<<" "<<sum<<'\n';
	int xx=lu[x].a;
	int yy=lu[x].b;
	int cnt=0;
	if(ok[xx]==0)
	{
		cnt++;
	}
	if(ok[yy]==0)
	{
		cnt++;
	}
	ok[xx]++;
	ok[yy]++;
	dfs(x+1,sum+lu[x].k,k+cnt);
	ok[xx]--;
	ok[yy]--;
	dfs(x+1,sum,k);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		int u,v;
		cin>>u>>v>>w[i];
		lu[i].a=u;
		lu[i].b=v;
		lu[i].k=w[i];
	}
	for(int j=1;j<=k;++j)
	{
		cin>>c[j];
		for(int i=1;i<=n;++i)
		{
			cin>>a[j][i];
		}
	}
	ans=0;
	if(k==0)
	{
		if(m==n-1)
		{
			for(int i=1;i<=m;++i)
			{
				ans+=w[i];
			}
		}
		else
		{
			dfs(1,0ll,0);
		}
	}
	cout<<ans;
//	cout<<'\n'<<"多组数据要换行&初始化"; 
//	cout<<'\n'<<"删注释&这句话&.exe&.out！！！！！！";
//	cout<<'\n'<<"删注释&这句话&.exe&.out！！！！！！";
//	cout<<'\n'<<"删注释&这句话&.exe&.out！！！！！！";
//	cout<<'\n'<<"删注释&这句话&.exe&.out！！！！！！";
//	cout<<'\n'<<"删注释&这句话&.exe&.out！！！！！！";
//	cout<<'\n'<<"删注释&这句话&.exe&.out！！！！！！";
	return 0;
}
//struct 
