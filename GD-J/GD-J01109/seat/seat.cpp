#include <bits/stdc++.h>
using namespace std;
const int N = 15;
struct edge
{
	int sc;
	int id;
};
int n,m;
edge a[N*N];
int lie,hang;
bool cmp(edge x,edge y)
{
	if (x.sc!=y.sc) return x.sc>y.sc;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++)
	{
		cin >> a[i].sc;
		a[i].id = i;
	}
	sort(a+1,a+n*m+1,cmp);
	int cu;
	for (int i=1;i<=n*m;i++)
	{
		if (a[i].id==1) 
		{
			cu = i;
			break;
		}
	}
	if (cu%n!=0)
	{
		lie = cu/n+1;
	}
	else if (cu%n==0)
	{
		lie = cu/n;
	}
	if (lie%2==1)
	{
		if (cu%n==0)
		{
			hang = n;
		}
		else if (cu%n!=0)
		{
			hang = cu%n;
		}
	}
	else if (lie%2==0)
	{
		if (cu%n==0)
		{
			hang = 1;
		}
		else if (cu%n!=0)
		{
			hang = n-(cu%n-1);
		}
	}
	cout << lie << " " << hang;
	return 0;
}
