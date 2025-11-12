#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N=1e5+10;
int t;
int n;

int ss[N];

int ans=0;

int f[101][101][101];

struct e{
	int x[4];
	int mx;
}a[N];

bool cmp(e x,e y)
{
	return abs(x.x[1]-x.x[2])>abs(y.x[1]-y.x[2]);
}

bool cmp1(e x,e y)
{
	return x.mx<y.mx;
}

int sum=0;
int s1,s2,s3;
void dfs(int x)
{
	if(sum+ss[x]<ans) return;
	if(x>n)
	{
		ans=max(ans,sum);
		return;
	}
	if(s1<n/2&&sum+a[x].x[1]>f[s1+1][s2][s3])
	{
		++s1;
		sum+=a[x].x[1];
		f[s1][s2][s3]=sum;
		dfs(x+1);
		sum-=a[x].x[1];
		--s1;
	}
	if(s2<n/2&&sum+a[x].x[2]>f[s1][s2+1][s3])
	{
		++s2;
		sum+=a[x].x[2];
		f[s1][s2][s3]=sum;
		dfs(x+1);
		sum-=a[x].x[2];	
		--s2;
	}
	if(s3<n/2&&sum+a[x].x[3]>f[s1][s2][s3+1])
	{
		++s3;
		sum+=a[x].x[3];
		f[s1][s2][s3]=sum;
		dfs(x+1);
		sum-=a[x].x[3];
		--s3;
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		
		int n2=n/2;
		
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d%d",&a[i].x[1],&a[i].x[2],&a[i].x[3]);
			a[i].mx=max(max(a[i].x[1],a[i].x[2]),a[i].x[3]);
		}		
		
		if(n>200)
		{
			
			sort(a+1,a+n+1,cmp);
			
			int sum=0;
			int x1=0,x2=0,x3=0;
			
			for(int i=1;i<=n;++i)
			{
				int h=0,mmx=0;
				if(x1<n2&&a[i].x[1]>mmx) mmx=a[i].x[1],h=1;
				if(x2<n2&&a[i].x[2]>mmx) mmx=a[i].x[2],h=2;
				if(x3<n2&&a[i].x[3]>mmx) mmx=a[i].x[3],h=3;
				if(h==1) ++x1;
				if(h==2) ++x2;
				if(h==3) ++x3;
				sum+=mmx;
			}
			
			printf("%d\n",sum);			
		}
		else
		{
			sort(a+1,a+n+1,cmp);
			ss[n+1]=0;
			for(int i=n;i>=1;--i)
			{
				ss[i]=ss[i+1]+max(max(a[i].x[1],a[i].x[2]),a[i].x[3]);
			}
			for(int i=0;i<=n2;++i) for(int j=0;j<=n2;++j) for(int k=0;k<=n2;++k) f[i][j][k]=0;
			ans=0;
			sum=s1=s2=s3=0;
			dfs(1);
			printf("%d\n",ans);
		}

		
	}
	
	return 0;
}
