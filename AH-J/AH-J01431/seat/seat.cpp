#include <bits/stdc++.h>
using namespace std;
#define LL long long
const LL N = 1e6;
LL a[N];
bool cmp(const LL &x,const LL &y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	LL n,m,x;
	cin>>n>>m>>x;
	for(LL i = 2;i<=n*m;i++){
		cin>>a[i];
	}
	a[1]=x;
	sort(a+1,a+n+1,cmp);
	
	
	return 0;
}
