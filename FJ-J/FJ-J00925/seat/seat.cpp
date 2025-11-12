#include<bits/stdc++.h>
using namespace std;
using lld = long long;
const lld siz = 1e5+5;
const lld mod = 1e9+7;
using pll = pair<lld,lld>;

lld n,m,x,y,s,sum = 1,tmp;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld %lld%lld",&n,&m,&s);
	for(int i=2;i<=n*m;i++)
	{
		scanf("%lld",&tmp);
		sum+=tmp>s;
	}
	x = sum/n+(sum%n!=0);
	y = sum%n?sum%n:n;
	printf("%lld %lld",x,x%2?y:(n-y+1));
	return 0;
}
