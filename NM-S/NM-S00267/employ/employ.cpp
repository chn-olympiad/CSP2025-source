#include<bits/stdc++.h>
using namespace std;
string a;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,ans=1,i,num=0;
	scanf("%lld%lld",&n,&m);
	cin>>a;
	for(i=1;i<=n;++i)
	{
		scanf("%lld",&m);
		if(m!=0) num++;
	} 
	for(i=1;i<=num;++i)
	{
		ans=(ans*i)%998244353ll;
	}
	cout<<ans;
	return 0;
}
