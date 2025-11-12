#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+20,M=2e6;
int n,m,k1,f[N],ans,sum,mon[15],mon1[15][N],mm;
vector<int> v;
struct ss
{
	int x,y,len;
}a[M];
bool cmp(ss x,ss y)
{
	return x.len<y.len;
}
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k1;
	mm=m;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].len);
	for(int i=1;i<=k1;i++)
	{
		cin>>mon[i];
		for(int j=1;j<=n;j++)
		{
			cin>>mon1[i][j];
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int xx=a[i].x,yy=a[i].y;
		if(find(xx)!=find(yy))
		{
			f[xx]=yy;
			ans+=a[i].len;
			sum++;
		}
		if(sum==n-1) break;
	}
	for(int i=1;i<=k1;i++)
	{
		for(int j=1;j<=i;j++) v.push_back(j);
		v.push_back(15);
		while(1)
		{
			for(int k=1;k<=n+10;k++) f[k]=k;
			for(int k=0;k<i;k++)
			{
				for(int p=1;p<=n;p++)
				{
					a[++m].x=p,a[m].y=n+v[k],a[m].len=mon1[v[k]][p];
				}
			}
			int ans1=0,sum1=0;
			for(int k=0;k<i;k++) ans1+=mon[v[k]];
			sort(a+1,a+m+1,cmp);
			for(int k=1;k<=m;k++)
			{
				int xx=a[k].x,yy=a[k].y;
				if(find(xx)!=find(yy))
				{
					f[xx]=yy;
					ans1+=a[k].len;
					sum1++;
				}
				if(sum1==n+i-1) break;
			}
			ans=min(ans,ans1);
			m=mm;
			bool pd=false;
			for(int k=i-1;k>=0;k--)
			{
				if(v[k]<k1&&v[k]<v[k+1]-1)
				{
					pd=true;
					v[k]++;
					for(int j=k+1;j<i;j++) v[k]=v[k-1]+1;
					break;
				}
			}
			if(!pd) break;
		}
		v.clear();
	}
	cout<<ans;
	return 0;
}
