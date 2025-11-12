#include<bits/stdc++.h>
using namespace std;
int n, m, r, arr[110], a[15][15];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) cin >> arr[i];
	r = arr[1];
	sort(arr + 1, arr + 1 + n * m);
	int in = n * m + 1;
	
	for(int i = 1;i <= m;i++) {
		if(i % 2 != 0) {
			for(int j = 1;j <= n;j++) 
			{
				a[j][i] = arr[--in];
				if(a[j][i] == r)
				{
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
		else {
			for(int j = n;j >= 1;j--) 
			{
				a[j][i] = arr[--in];
				if(a[j][i] == r)
				{
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
	}
	
	
	
	return 0;
}
