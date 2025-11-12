#include <bits/stdc++.h>
using namespace std;
int n,m,a,idx;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> a;
	for(int i = 1;i < n * m;i ++)
	{
		int x;cin >> x;
		if(a > x)
		{
			idx = i;
			break;
		}
	}
	if(idx == 0) idx = n * m;
	int p = idx / n,q = idx % n;
	if(q == 0) q = n;
	else p ++;
	
	if(p % 2 == 0) cout << p << ' ' << n - q + 1;
	else cout << p << ' ' << q;
	
	return 0; 
}
