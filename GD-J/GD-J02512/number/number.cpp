#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll a[1000005], n;
bool check (char c) 
{
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') {
		return true;
	}
	return false;
}
int main () 
{
//	freopen ("number.in", "r", stdin);
//	freopen ("number.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	cin >> s;
	for (int i = 0; i < s.size (); i++) 
	{
		if (check (s[i])) {
			n++;
			a[n] = s[i] - '0';
		} 
	}
	sort (a + 1, a + n + 1);
	for (int i = n; i >= 1; i--) 
	{
		cout << a[i];
	}
//	
//	for (int i = n; i >= 1; i++) 
//	{
//		cout << a[i];
//	}
    return 0;	
} 
