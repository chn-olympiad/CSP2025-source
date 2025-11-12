#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=100+10;
LL a[N],n,m,sum[N][N],tmp;
bool cmp(const int &x,const int &y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(LL i=1;i<=n*m;i++)scanf("%lld",&a[i]);
	tmp=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(LL i=1;i<=m;i++)
	{
		if(i%2==0)
			for(LL j=n;j>=1;j--)
				sum[i][j]=a[(i-1)*n+(n-j)+1];
		if(i%2==1) 
			for(LL j=1;j<=n;j++)
				sum[i][j]=a[(i-1)*n+j];	
	}
	for(LL i=1;i<=m;i++)
		for(LL j=1;j<=n;j++)
			if(sum[i][j]==tmp)
			{
				cout<<i<<" "<<j;
				return 0;
			}
	return 0;
}
