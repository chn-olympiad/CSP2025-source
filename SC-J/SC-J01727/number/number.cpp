#include <queue>
#include <string>
#include <bits/stdc++.h>
#define ll long long 
#define int ll
#define fi first
#define se second
#define mk make_pair
#define mem(a , x) memset(a , x , sizeof(a))
#define ls x << 1
#define rs x << 1 | 1
using namespace std;
ll const N = 1e5 + 10;
ll num[N] , n;
string s;
signed main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	n = s.length();
	for (int i = 0;i < n;i ++) num[(ll)s[i]] ++;
	for (int i = '9';i >= '0';i --)
		for (int j = 1;j <= num[i];j ++) cout << char(i);
	return 0;
}
/*

*/