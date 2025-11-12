#include <bits/stdc++.h>
using namespace std;
#define int long long

int read()
{
	char c=getchar();
	int x=0,f=1;
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=2e5+10;
struct node
{
	int a,b,c;
	int maxx,idx;
}a[N];
int n;
int f[201][101][101][101];

bool cmp1(node a,node b)
{
	return a.maxx>b.maxx;
}
bool cmp2(node a,node b)
{
	return a.maxx<b.maxx;
}
bool check(int mid)
{
	sort(a+1,a+1+n,cmp1);
	int ans=0;
	int t=n/2;
	int b[5]={0,0,0,0,0};
	for(int i=1;i<=n;i++)
	{
		if(a[i].idx==1)
		{
			if(b[1]+1>t)
			{
				if(a[i].b>a[i].c)
				{
					if(b[2]+1>t)
					{
						b[3]++;
						ans+=a[i].c;
					}else
					{
						b[2]++;
						ans+=a[i].b;
					}
				}else if(a[i].b<a[i].c)
				{
					if(b[3]+1>t)
					{
						b[2]++;
						ans+=a[i].b;
					}else 
					{
						b[3]++;
						ans+=a[i].c;
					}
				}else
				{
					if(b[2]<b[3])
					{
						b[2]++,ans+=a[i].b;
					}else b[3]++,ans+=a[i].c;
				}
			}
			else {
				b[1]++;
				ans+=a[i].maxx;
			}
		}
		
		if(a[i].idx==2)
		{
			if(b[2]+1>t)
			{
				if(a[i].a>a[i].c)
				{
					if(b[1]+1>t)
					{
						b[3]++;
						ans+=a[i].c;
					}else
					{
						b[1]++;
						ans+=a[i].a;
					}
				}else if(a[i].a<a[i].c)
				{
					if(b[3]+1>t)
					{
						b[1]++;
						ans+=a[i].a;
					}else 
					{
						b[3]++;
						ans+=a[i].c;
					}
				}else
				{
					if(b[1]<b[3])
					{
						b[1]++,ans+=a[i].a;
					}else b[3]++,ans+=a[i].c;
				}
			}
			else {
				b[2]++;
				ans+=a[i].maxx;
			}
		}
		
		if(a[i].idx==3)
		{
			if(b[3]+1>t)
			{
				if(a[i].b>a[i].a)
				{
					if(b[2]+1>t)
					{
						b[1]++;
						ans+=a[i].a;
					}else
					{
						b[2]++;
						ans+=a[i].b;
					}
				}else if(a[i].b<a[i].a)
				{
					if(b[1]+1>t)
					{
						b[2]++;
						ans+=a[i].b;
					}else 
					{
						b[1]++;
						ans+=a[i].a;
					}
				}else
				{
					if(b[2]<b[1])
					{
						b[1]++,ans+=a[i].a;
					}else b[2]++,ans+=a[i].b;
				}
			}
			else {
				b[3]++;
				ans+=a[i].maxx;
			}
		}
	}
//	cout<<ans<<"\n";
	if(ans>=mid)return true;
	
	
	sort(a+1,a+1+n,cmp2);
	ans=0;
	b[1]=b[2]=b[3]=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].idx==1)
		{
			if(b[1]+1>t)
			{
				if(a[i].b>a[i].c)
				{
					if(b[2]+1>t)
					{
						b[3]++;
						ans+=a[i].c;
					}else
					{
						b[2]++;
						ans+=a[i].b;
					}
				}else if(a[i].b<a[i].c)
				{
					if(b[3]+1>t)
					{
						b[2]++;
						ans+=a[i].b;
					}else 
					{
						b[3]++;
						ans+=a[i].c;
					}
				}else
				{
					if(b[2]<b[3])
					{
						b[2]++,ans+=a[i].b;
					}else b[3]++,ans+=a[i].c;
				}
			}
			else {
				b[1]++;
				ans+=a[i].maxx;
			}
		}
		
		if(a[i].idx==2)
		{
			if(b[2]+1>t)
			{
				if(a[i].a>a[i].c)
				{
					if(b[1]+1>t)
					{
						b[3]++;
						ans+=a[i].c;
					}else
					{
						b[1]++;
						ans+=a[i].a;
					}
				}else if(a[i].a<a[i].c)
				{
					if(b[3]+1>t)
					{
						b[1]++;
						ans+=a[i].a;
					}else 
					{
						b[3]++;
						ans+=a[i].c;
					}
				}else
				{
					if(b[1]<b[3])
					{
						b[1]++,ans+=a[i].a;
					}else b[3]++,ans+=a[i].c;
				}
			}
			else {
				b[2]++;
				ans+=a[i].maxx;
			}
		}
		
		if(a[i].idx==3)
		{
			if(b[3]+1>t)
			{
				if(a[i].b>a[i].a)
				{
					if(b[2]+1>t)
					{
						b[1]++;
						ans+=a[i].a;
					}else
					{
						b[2]++;
						ans+=a[i].b;
					}
				}else if(a[i].b<a[i].a)
				{
					if(b[1]+1>t)
					{
						b[2]++;
						ans+=a[i].b;
					}else 
					{
						b[1]++;
						ans+=a[i].a;
					}
				}else
				{
					if(b[2]<b[1])
					{
						b[1]++,ans+=a[i].a;
					}else b[2]++,ans+=a[i].b;
				}
			}
			else {
				b[3]++;
				ans+=a[i].maxx;
			}
		}
	}
	if(ans>=mid)return true;
	return false;
}

void solve()
{

	 n=read();
	 bool flag=true;
	int r=0;
	for(int i=1;i<=n;i++)
	{
		a[i].a=read(),a[i].b=read(),a[i].c=read();
		a[i].maxx=max({a[i].a,a[i].b,a[i].c});
		if(a[i].maxx==a[i].a)a[i].idx=1;
		if(a[i].maxx==a[i].b)a[i].idx=2;
		if(a[i].maxx==a[i].c)a[i].idx=3;
		if(a[i].b||a[i].c)flag=false;
		r+=a[i].maxx;
	}
	if(n<=200)
	{
		memset(f,0,sizeof f);
		f[0][0][0][0]=0;
		int kk=n/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=kk;j++)
			{
				for(int k=0;k<=kk;k++)
				{
					for(int u=0;u<=kk;u++)
					{
						if(u==j&&j==k&&j==0)continue;
						if(j+k+u!=i)continue;
						if(j>=1)f[i][j][k][u]=max(f[i][j][k][u],f[i-1][j-1][k][u]+a[i].a);
						if(k>=1)f[i][j][k][u]=max(f[i][j][k][u],f[i-1][j][k-1][u]+a[i].b);
						if(u>=1)f[i][j][k][u]=max(f[i][j][k][u],f[i-1][j][k][u-1]+a[i].c);						
						//cout<<i<<" "<<j<<" "<<k<<" "<<u<<" "<<f[i][j][k][u]<<"\n";
					}
				}
			}
		}
		
		int ans=0;
		for(int i=0;i<=kk;i++)
			for(int j=0;j<=kk;j++)
				for(int k=0;k<=kk;k++)
				{
					if(i+j+k==n)
					{
						int t=ans;
						ans=max(ans,f[n][i][j][k]);
					}
				}
		cout<<ans<<"\n";
	}
	else if(flag)
	{
		sort(a+1,a+1+n,cmp1);
		int ans=0;
		for(int i=1;i<=n/2;i++)ans+=a[i].a;
		cout<<ans<<"\n";
	}else
	{
		int l=0;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(check(mid))l=mid;
			else r=mid-1;
		}
		cout<<l<<"\n";
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--)solve();
	return 0;
}
