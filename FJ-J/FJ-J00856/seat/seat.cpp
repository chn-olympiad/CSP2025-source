#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
int cmp(int x,int y)
{
	return x>y;
}
int a[11145],p,b[514][514];
int h,l;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(p==a[i])
		{
			cnt=i;
			break;
		}
	}
	if(cnt%n==0)
	{
		if((cnt/n)%2==1)
		{
			cout<<cnt/n<<" "<<n;
			return 0;
		}
		if((cnt/n)%2==0)
		{
			cout<<cnt/n<<" "<<1;
			return 0;
		}
	}
	l=cnt/n+1;
	if(l%2==1)
	{
		cout<<l<<" "<<cnt%n;
		return 0;
	}
	if(l%2==0)
	{
		cout<<l<<" "<<n-(cnt%n)+1;
		return 0;
	}
	return 0;
}
