#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;
long long n,m,a[1001],p,c,r,pc=1;
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)cin>>a[i];
	long long cj=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(long long i=1;i<=n*m;i++)
		if(a[i]==cj){p=i;break;}
	if(p<=n)c=1;
	else
	{
		c=2;
		while(1)
		{
			pc++;
			if(c%2==0 && p<=pc*n)break;
			else if(c%2==1 && p<=(pc-1)*n+1)break;
			c++;
		}	
	}
	long long r=p-(c-1)*n;
	if(c%2==1)cout<<c<<" "<<r;
	else cout<<c<<" "<<n-r+1;
	return 0;
}
