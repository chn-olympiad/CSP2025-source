#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001][5],sum[5];
struct node
{
	int a,b,c,d;
}
f[100001];
bool cmp(node x,node y)
{
	if(x.a-x.c==y.a-y.c)
	{
		return x.a>y.a;
	}
	return x.a-x.c>y.a-y.c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long ans=0;
		memset(f,0,sizeof(f));
		memset(sum,0,sizeof(sum));
		int k=n/2;
		for(int i=1;i<=n;i++)
		{
			int minn=INT_MAX,maxx=INT_MIN;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(maxx<a[i][j])
				{
					maxx=a[i][j];
					f[i].b=j;
				}
				if(minn>a[i][j])
				{
					minn=a[i][j];
				}
			}
			f[i].a=maxx;
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]!=maxx && a[i][j]!=minn)
				{
					f[i].c=a[i][j];
					f[i].d=j;
				}
			}
		}
		sort(f+1,f+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(sum[f[i].b]+1<=k)
			{
				ans+=f[i].a; 
				sum[f[i].b]++;
			}
			else
			{
				ans+=f[i].c;
				sum[f[i].d]++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
