#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n;
int a[N];
long long res;
long long C(int x,int y)
{
	long long p1=1,p2=1;
	for(int i=x; i>=x-y+1; i--) p1*=i;
	for(int i=1; i<=y; i++) p2*=i;
	return p1/p2;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=3; i<=n; i++) res+=C(n,i);
	printf("%lld",res);
	return 0;
}
