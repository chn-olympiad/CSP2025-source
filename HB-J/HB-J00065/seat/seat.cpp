#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[105],n,m,c;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>c;
	a[1]=c;
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==c)
		{
			i--;
			cout<<i/n+1<<' ';
			if(i/n%2==1)cout<<n-i%n;
			else cout<<i%n+1;
			break;
		}
	}
	return 0;
}
