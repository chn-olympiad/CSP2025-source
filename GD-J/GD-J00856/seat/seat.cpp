#include <bits/stdc++.h>

using namespace std;

const int N=15,M=110;
int n,m;
int a[M];
bool valid(int y) { return 1<=y && y<=n; }

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	for (int i=1;i<=n*m;i++) cin >> a[i];
	
	int rk=0;
	for (int i=1;i<=n*m;i++) rk+=(a[i]>=a[1]);
	
	int x=1,y=1; int dir=1;
	while (--rk)
	{
		if (valid(y+dir)) y+=dir;
		else { x++, dir=-dir; }
	}
	cout << x << " " << y << "\n";
	  
	return 0;
}
