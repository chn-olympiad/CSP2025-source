#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5;
int n,m;
int a[N];
int r;
bool cmp(int aa,int bb)
{
	return aa>bb;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&a[1]);
	r=a[1];
	for(int i=2;i<=n*m;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n*m+1,cmp);
	int k;
	for(k=1;k<=n*m;k++)
	{
		if(a[k]==r) break;
	}
	int newx,newy;
	newx=(k-1)/n+1;
	if(newx%2==0) newy=n-((k-1)%n+1)+1;
	else newy=(k-1)%n+1;
	cout<<newx<<" "<<newy;
	return 0;
}
