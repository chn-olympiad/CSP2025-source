#include<bits/stdc++.h>
using namespace std;
const int M=3e6,N=1e4+20;
struct Node{
	int x,y;
	long long w;
};
Node l[M];
int n,m,k;
int c[20];
long long a[12][N];
int fa[N];
int find(int x)
{
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	return x;
}
bool cmp(Node aa,Node bb)
{
	return aa.w<bb.w;
}
int num;
long long km()
{
	long long ans=0;
	int cnt=0;
	sort(l+1,l+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		int x=l[i].x,y=l[i].y,w=l[i].w;
		int fx=find(x),fy=find(y);
		if(fx!=fy)
		{
			cnt++;
			ans+=w;
			fa[fx]=fy;
		}
		if(cnt==num-1)
			break;
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int op=0;
	for(int i=1;i<=m;i++)
		cin>>l[i].x>>l[i].y>>l[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]==0) op++;
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
			fa[i]=i;
		num=n;
		long long ans=km();
		cout<<ans<<endl;
		return 0;
	}
	if(op==k)
	{
		for(int i=1;i<=n+k;i++)
			fa[i]=i;
		num=n+k;
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
			{
				m++;
				l[m].x=i+n,l[m].y=j,l[m].w=a[i][j];
			}
		long long ans=km();
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n+k;i++)
			fa[i]=i;
	num=n;
	long long ans=km();
	for(int i=1;i<=k;i++)
	{
		long long sum=c[i];
		num++;
		for(int ii=1;ii<=n+k;ii++)
			fa[ii]=ii;
		for(int j=1;j<=n;j++)
		{
			m++;
			l[m].x=i+n,l[m].y=j,l[m].w=a[i][j];
		}
		sum+=km();
		if(sum<ans) ans=sum;
		else
		{
			num--;
			m--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
