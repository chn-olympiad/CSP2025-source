#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1010],ss,x,y,s;
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n*m;i++) cin>>a[i];
	ss=a[0];
	sort(a,a+n*m,cmp);
	for (int i=0;i<n*m;i++)
	{
		if (a[i]==ss)
		{
			s=i+1;
			break;
		}
	}
	x=ceil(s*1.0/n);
	y=(x%2?(s-1)%n+1:n-(s-1)%n);
	cout<<x<<' '<<y;
	return 0;
}

