#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node
{
	int x,y,w;
}a[N],b[N];
int s[11],p[11][N],fa[N],tmp,ans=INT_MAX,n,m,k;
bool comp(node a1,node a2)
{
	return a1.w<a2.w;
}
int Father(int x)
{
	if (fa[x]!=x)
		return fa[x]=Father(fa[x]);
	return x;
}
void dfs(int x,int sum)
{
	if (x>k)
	{
		//cout<<tmp<<" "<<sum<<"\n"; 
		for (int i=1;i<=tmp;++i)
			b[i]=a[i];
		for (int i=1;i<=n+k;++i)
			fa[i]=i;
		sort(b+1,b+tmp+1,comp);
		//int cnt=0;
		for (int i=1;i<=tmp;++i)
		{
			int x=b[i].x,y=b[i].y,
			f1=Father(x),f2=Father(y);
			//cout<<b[i].x<<" "<<b[i].y<<" "<<b[i].w<<"\n";
			if (f1==f2)
				continue;
			fa[f1]=f2;
			if (sum>=ans)
				return;
			sum+=b[i].w;
			//cout<<b[i].w<<" ";
		}
		//cout<<"\n"<<sum<<"\n";
		ans=min(ans,sum); 
		return;
	}
	//cout<<x<<"\n";
	int cnt=tmp;
	for (int i=1;i<=n;++i)
		a[++tmp]={x+n,i,p[x][i]};
	if (sum+s[x]<ans)
		dfs(x+1,sum+s[x]);
	tmp=cnt;
	dfs(x+1,sum);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),
	cin.tie(0),cout.tie(0); 
	cin>>n>>m>>k;
	for (int i=1;i<=m;++i)
		++tmp,
		cin>>a[tmp].x>>a[tmp].y>>a[tmp].w;
		//cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].w<<"\n";
		//cout<<tmp<<"\n";
	int maxx=0;
	for (int i=1;i<=k;++i)
	{
		cin>>s[i];
		maxx=max(maxx,s[i]);
//		cout<<s[i]<<"\n";
		for (int j=1;j<=n;++j)
			cin>>p[i][j],
			maxx=max(maxx,p[i][j]);
			//cout<<p[i][j]<<" "<<i<<" "<<j<<"\n";
	}
	if (maxx==0)
	{
		cout<<"0\n";
		return 0;
	}
	dfs(1,0);
	cout<<ans<<"\n";
	return 0;
}
