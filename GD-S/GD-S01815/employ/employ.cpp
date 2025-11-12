#include<bits/stdc++.h>
#define ll long long
const int N=3e6+10;
const int M=998244353;
const int inf=0x3f3f3f3f;
using namespace std;
int n,m,c[N];
char a[N];
ll ans=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,a);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=n;i>=1;i--)
	{
		ans*=i;
		ans%=M;
	}
	printf("%lld",ans);
	return 0;
}
/*
100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19

*/
