# include <bits/stdc++.h>
using namespace std;
int n,m,maxa,mm;
long long cnt=0;
bool b[10005];
int c[10005];
int a[10005];
void dfs(int k,int sum,int mm)
{
	if (k==m+1 && sum>mm*2)
	{
		cnt =(cnt+1)%998244353;
	}
	for (int i=1;i<=n;i++)
	{
		if (b[i]==0)
		{
			c[k]=a[i];
			b[i]=1;
			dfs(k+1,sum+a[i],max(mm,a[i]));
			b[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		maxa = max(maxa,a[i]);
	}
	sort(a+1,a+1+n);
	if(n==3)
	{
		if (a[1]+a[2]+a[3]>maxa*2)
		{
			cout << 1;
		}else
		{
			cout << 0;
		}
		return 0;
	}
	long long cnt1=0;
	long long t=2;
	long long s=3;
	for (int i=3;i<=n;i++)
	{
		mm=0;
		m=i;
		cnt=0;
		dfs(1,0,0);
		t=t*s%998244353;
		s=s+1;
		int cc=cnt/t%998244353;
		cnt1=(cnt1+cc)%998244353;
	}
	printf("%d",cnt1%998244353);
	return 0;
}
