#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mode=998244353;
int X,Y;
void exgcd(int a,int b)
{
	if(b==0)
	{
		X=1; Y=0;
		return;
	}
	exgcd(b,a%b);
	int t=X; X=Y; Y=t-a/b*Y;
}
int jie[5005],ny[5005];
int C(int n,int m)
{
	return jie[n]*ny[m]%mode*ny[n-m]%mode;
}
int n;
int a[5005];
void qsort(int l,int r)
{
	if(l>=r) return;
	int i=l,j=r,mid=a[rand()%(r-l+1)+l];
	while(i<=j)
	{
		while(a[i]<mid) i++;
		while(a[j]>mid) j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++; j--;
		}
	}
	qsort(i,r); qsort(l,j);
}
int f[5005];
int t[5005];
int solve(int x)
{
	int res=0;
	for(int i=1;i<=x;i++) res=(res+C(x,i))%mode;
	for(int i=1;i<=a[x+1];i++)
		res=(res-f[i]+mode)%mode;
	res=(res+t[a[x+1]])%mode;
	int r=x;
	for(int i=1;i<=x;i++)
	{
		if(a[i]>a[x+1]) res=(res-1+mode)%mode;
	}
	return res;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	srand(time(0));
	scanf("%lld",&n); jie[0]=ny[0]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		jie[i]=jie[i-1]*i%mode;
		exgcd(jie[i],mode); X=(X+mode)%mode;
		ny[i]=X; t[a[i]]++;
	}
	qsort(1,n); f[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=a[n];j>=a[i];j--)
		{
			f[j]=(f[j]+f[j-a[i]])%mode;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=(ans+solve(i-1))%mode;
		t[a[i]]--;
	}
	printf("%lld",ans);
	return 0;
}
/*
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1


*/
