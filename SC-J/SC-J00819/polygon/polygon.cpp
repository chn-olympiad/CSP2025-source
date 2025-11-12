#include<bits/stdc++.h>
using namespace std;
long long n,s,a[5020],i,u,o,j,l,b[5020];
void dfs(long long h,long long ss,long long zimo)
{
	if(h==0)
	{
		if(a[i]<ss)s++;
		s%=998244353;
		return ;
	}
	for(long long k=1;k<zimo;k++)dfs(h-1,ss+a[k],k);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(i=3;i<=n;i++)for(j=3;j<=i;j++)dfs(j-1,0,i);
	cout<<s;
	return 0;
}