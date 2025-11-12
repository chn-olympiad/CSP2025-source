#include <bits/stdc++.h>
#define int long long
using namespace std;
inline bool cmp(int a,int b)
{
	return a>b;
}
const int N=150;
int n,m,a[N],seat[1005][1005],k;
int32_t main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	k=n*m;
	for(int i=1; i<=n*m; i++)
		scanf("%lld",&a[i]);
	int R=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=m; i>=1; i--)
	{
		if(i%2!=0)
		{
			for(int j=n;j>=1; j--,k--)
				seat[i][j]=a[k];
		}
		else
		{
			for(int j=1; j<=n; j++,k--)
				seat[i][j]=a[k];
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(seat[i][j]==R)
				return printf("%lld %lld",i,j),0;
	return 0;
}
/*
while(1)
	rp++!;
*/
