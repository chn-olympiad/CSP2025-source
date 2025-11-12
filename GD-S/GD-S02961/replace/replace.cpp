#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n , q;
string a[N] , b[N];
string t[N][12]; 
int main()
{
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i] >> b[i];
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i] >> b[i];
	for(int i = 1 ; i <= q ; i++)
		cin >> t[i][1] >> t[i][2];
	return 0;
}
