#include<bits/stdc++.h>
#define ll long long
#define N (int)510
#define MOD 998244353
using namespace std;

int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld %lld",&n,&q);
	for(int i=1; i<=q; i++)
		printf("%lld\n",(i*4*11*5*7*2*8*13)%3%2);
	return 0;
}


