#include<bits/stdc++.h>
#define ll long long
#define Int __int128
#define pb push_back
#define rep(i , a , b) for (int i = (a); i <= (b); i++)
#define drep(i , a , b) for (int i = (a); i >= (b); i--)
using namespace std;
const int maxn = 1e6+5;
int n , m , a[maxn] , t;
signed main()
{
//	freopen("seat.in" , "r" , stdin);
//	freopen("seat.out" , "w" , stdout);
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m;
	rep(i , 1 , n*m)cin >> a[i];
	t=a[1];
	sort(a + 1 , a + n * m + 1 , greater<int>());
	bool f = 0;
	int cnt = 0;
	rep(i , 1 , m)
	{
		f^=1;
		if (f)
		{
			rep(j , 1 , n)
			{
				cnt++;
				if (a[cnt] == t){cout << i << " " << j << "\n";return 0;}
			}
		}
		else
		{
			drep(j , n , 1)
			{
				cnt++;
				if (a[cnt] == t){cout << i << " " << j << "\n";return 0;}
			}
		}
	}
	return 0;
}

/*
mem file time
author: YBTL sjwhsss RP++
贪心，dp，构造，二分，随机化，哈希，图论建模，根号分治，分块，分治，线段树分治，扫描线
*/