#include<iostream> 
#include<cstdio> 
#include<cmath> 
#include<string.h>
using namespace std;
const long long MOD=998244353;
int a[5010];
int n;
long long s;
long long polygon(int x)
{
	if(x==0)
		return 1;
	if(x==1)
		return n;
	return (polygon(x-1)*(n-x+1)/x)%MOD;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<=n-3;i++)
	{
		s+=polygon(i)%MOD;
		s%=MOD;
	}
	cout<<s;
	return 0;
}
