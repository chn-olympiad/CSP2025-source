#include<bits/stdc++.h>
using namespace std;
int a[5050],n;
unsigned long long s[5050],k=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	s[1]=1;
	s[0]=1;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		if(i>1) s[i]=s[i-1]*i;
	}
	if(n<3)
	{
		cout<<"0";
		return 0;
	}
	if(n==3)
	{
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3]) cout<<"1";
		else cout<<"0";
		return 0;
	}
	for(int i=3;i<=n;i++) 
	k+=(s[n]/s[n-i]/s[i]);	
	printf("%lld",k);
	return 0;
}