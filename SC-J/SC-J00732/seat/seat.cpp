#include <iostream>
#include <algorithm>

using namespace std;

int n,m,a[100];

int main(void)
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	cin >> n >> m;
	int l = n * m;
	cin >> a[0];
	for(int i = 1;i <= l;i++)
	{
		int t;
		cin >> t;
		if(t > a[0])
		{
			a[i] = t;
		}
		else
		{
			l--;
		}
	}
	sort(a, a + l);
	int lie,hang;
	lie = l / n;
	if(l % n == 0)
	{
		if(lie % 2 == 0)
		{
			cout << lie << ' ' << 1;
		}
		else
		{
			cout << lie << ' ' << n;
		}
	}
	else
	{
		if(lie % 2 == 0)
		{
			hang = l % n;
		}
		else
		{
			hang = n - l % n + 1;
		}
		cout << lie + 1 << ' ' << hang;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}