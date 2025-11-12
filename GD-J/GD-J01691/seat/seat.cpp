#include<bits/stdc++.h>
using namespace std;
long long n,m,s,a[1000005],bh;
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	if(a[i]==s)
	bh=i;
	long long y=(bh-1)/n+1;
	long long x=(bh-1)%n+1;
	if(y%2==1)
	cout<<y<<" "<<x;
	else
	cout<<y<<" "<<n-x+1;
	return 0;
}
