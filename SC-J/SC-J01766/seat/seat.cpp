#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],r,h = 0;
	cin >> n >> m;
	cin >> r;
	a[1] = r;
	for (int i = 2;i <= n * m;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n * m + 1);
	for (int i = n * m;i >= 1;i--)
	{
		if (a[i] == r){
			h = n * m - i + 1;
			break;
		}
	}
	int lie = 0,hang = 0;
	if (h % n == 0){
		lie = h / n;
		if (lie % 2 == 1){
			hang = n;
		}
		else if (lie % 2 == 0){
			hang = 1;
		}
	}
	else{
		lie = h / n + 1;
		if (lie % 2 == 0){
			hang = n - (h % n) + 1;
		}
		else if (lie % 2 == 1){
			hang = h % n;
	    }
	}
	cout << lie << ' ' << hang;
	return 0;
}