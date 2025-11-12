#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10+1+50;
const int M=1e6+1e5+10+50;
struct bin{
	int x,y;
	long long d;
}a[M];
int t,n,k,m;
bool cmp(bin x,bin y)
{
	return x.d<y.d;
}
int fa[N];
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
int citym[11];
bool city[11];
void solve1_4()
{
	sort(a+1,a+1+t,cmp);
	long long ans=0,kk=0;
	for(int i=1;i<=t;i++)
	{
		int fx=find(a[i].x),fy=find(a[i].y);
		if(fx!=fy)
		{
			fa[fy]=fx;
			kk++;
			ans+=a[i].d;
			if(kk==n-1)
			{
				cout<<ans;
				return;
			}
		}
	}
}
void solveA()
{
	sort(a+1,a+1+t,cmp);
	long long ans=0,kk=0;
	for(int i=1;i<=t;i++)
	{
		int fx=find(a[i].x),fy=find(a[i].y);
		if(fx!=fy)
		{
			fa[fy]=fx;
			kk++;
			ans+=a[i].d;
			if(kk==n+k-1)
			{
				cout<<ans;
				return;
			}
		}
	}
}
inline int in()
{
	long long num=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		num=num*10+c-'0';
		c=getchar();
	}
	return num*f;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int x,y;
	long long d;
	n=in();m=in();k=in();
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		a[++t].x=in();a[t].y=in();a[t].d=in();
	}
	bool flag=0;
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
		{
			d=in();
			if(j==0&&d!=0) flag=1;
			if(j!=0) a[++t].x=i+n,a[t].y=j,a[t].d=d;
		}
	if(k==0) solve1_4();
	else if(!flag) solveA();
	return 0;
}
