#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,x,s;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%lld",&x),s+=x;
	printf("%lld",s);
	return 0;
}
