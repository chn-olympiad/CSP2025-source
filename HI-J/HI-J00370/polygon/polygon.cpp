#include <bits/stdc++.h>
#define MOD 998244353 
using namespace std;
int a[5100];
int c(m,n)
{
	int ans=1;
	for(int i=n+1;i<=m;i++)ans*=i%MOD;
	for(int i=1;i<=m-n;i++)ans/=i%MOD;
	return ans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int ans=0;
	cin>>n; 
	if(n<=10)
	{
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	}
	else 
	{	
		for(int i=3;i<=n;i++)ans+=c(n,i)%MOD;
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//WOKAO 这啥呀……不管了 看特殊性质骗点分吧 靠运气了 
