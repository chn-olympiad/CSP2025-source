#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n , m , xiaor , jli;
int lsans = 0;
int a[N];
int main() {
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}xiaor = a[1];
	sort(a + 1 , a + 1 + n * m);
	for(int i = 1;i <= m;i++)
	{
		if(i % 2 == 1)
		{
			for(int j = 1;j <= n;j++)
			{
				lsans ++;
				if(a[n * m - lsans + 1] == xiaor)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}else{
			for(int j = n;j >= 1;j--)
			{
				lsans ++;
				if(a[n * m - lsans + 1] == xiaor)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
