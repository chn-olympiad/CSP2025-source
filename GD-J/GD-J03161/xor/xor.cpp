#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1e05*5+10;
long long n,m,k,a[MAXN],ans,xza,xzb;
void xb()
{
	long long j=0,o=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]%2==0)
			o++;
		else
			j++;
	}
	if(k==0)
		printf("%lld",o);
	else
		printf("%lld",j);
	return ;
}
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]==k)
			ans++;
		if(a[i]==1)
			xza++;
		if(a[i]<=1)
			xzb++;
	}
	if(xza==n&&k==0)
	{
		printf("%lld",0);
		return 0;
	}
	if(xzb==n&&k<=1)
	{
		xb();
		return 0; 
	}
	return 0;
}
//不同为0，相同为1 
