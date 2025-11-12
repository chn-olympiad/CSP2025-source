#include<bits/stdc++.h>
using namespace std;
int a[5010],n,i,j,b[5010],s,maxx;
long long ans=0;
void f(int x)
{
	memset(b,0,sizeof(b));
	maxx=0;s=0;
	b[1]=x;s=1;
	for(i=3;i<=n-x+1;i++)
	{
		for(j=1;j<i;j++)
		{
			b[++s]=
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	f(1);
	cout<<ans%998244353;
	return 0;
}
