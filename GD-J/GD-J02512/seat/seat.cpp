#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[10005], Small_R;
void work ();
/*
2 2 
99 97 100 98
*/ 
int main () 
{
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	cin  >> n >> m;
	for (int i = 1; i <= n * m; i++) 
	{
		cin >> a[i];
	}
	Small_R = a[1];
	work ();
    return 0;	
} 

void work () 
{
	sort (a + 1, a + n * m + 1, greater <ll> ());
	ll x = 1, y = 1;
	bool flag = false;
	for (int i = 1; i <= n * m; i++) 
	{
	    if (a[i] == Small_R) {
	    	cout << x << " " << y << "\n";
            return ;
		}
		if (!flag) {
			if (y < n) {
				y++;
			} else {
				x ++;
				y = n;
				flag = true;
			}
		} else {
			if (y > 1) {
				y--;
			} else {
				x++;
				y = 1;
				flag = false;
			}
		}
	}
}
