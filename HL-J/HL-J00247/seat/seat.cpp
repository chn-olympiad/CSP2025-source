#include <bits/stdc++.h>
using namespace std;
int n,m,x,q,a[105],u,t,e;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	u=n*m;
	for (int i=1;i<=u;i++)
	{
		cin >> a[i];
	}
	x=a[1];
	sort(a+1,a+u+1,cmp);
	for (int i=1;i<=u;i++)
	{
		if (a[i]==x)
		{
			q=i;
			break;
		}
	}
	t=q/n;
	e=q%n;
	if (e==0)
	{
		if (t%2==0)cout << t << " " << 1;
		else cout << t << " " << n;
	}
	else
	{
		if (t%2==0)cout << t+1 << " " << e;
		else cout << t+1 << " " << n-e+1;
	}
	return 0;
}
