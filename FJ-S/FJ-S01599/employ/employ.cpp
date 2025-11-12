#include<bits/stdc++.h>
using namespace std;
long long n,m,a[501],l,d=1,g=998244353;
char c[501];
int main() 
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//Ren5Jie4Di4Ling5%
	scanf("%lld%lld",&n,&m);
	cin>>c;
	for(int i=1;i<=n;i++)
	{
		if(c[i]=='1')
		{
			l++;
		}
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=l;i++)
	{
		d*=i%g;
	}
	printf("%lld\n",d);
	return 0;
}
