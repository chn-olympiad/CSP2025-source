#include<bits/stdc++.h>
#define int long long
#define hash ZhaoAk
#define y1 zhaoshenghao666
#define maxn 15
#define endl "\n"
#define nullptr 0
#define I ios::sync_with_stdio (0);
#define AK cin.tie (0);
#define CSP cout.tie (0);


using namespace std;


string s;
int tong[maxn];


signed main()
{
	I AK CSP
	freopen ("number.in" ,"r" ,stdin);
	freopen ("number.out" ,"w" ,stdout);
	cin >> s;
	int n = s.size ();
	s = "#" + s;
	for (int i = 1 ;i <= n ;i ++)
		if (isdigit (s[i]))
			tong[s[i] - '0'] ++;
	for (int i = 9 ;i >= 0 ;i --)
		for (int j = 1 ;j <= tong[i] ;j ++)
			cout << i;
	return 0;
}//Code by Lyyq.
//wage