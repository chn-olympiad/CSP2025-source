#include <bits/stdc++.h>
#define int long long
using namespace std;
struct mem{
	int ID,task;
}a[10005];
bool cmp(mem a1,mem a2)
{
	return a1.task>a2.task;
}
int n,m,r,c;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].task;
		a[i].ID=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i].ID==1)
		{
			int r,c=(i-1)/n+1;
			int before=(c-1)*n;
			r=i-before;
			if(c%2==0)r=n+1-r;
			cout<<c<<' '<<r;
			break;
		}
	return 0;
}
