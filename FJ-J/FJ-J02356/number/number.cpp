#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e6 + 11451;

string s;

ll cnt = 1;
ll a[N]; 

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	ll l = s.length();
	for(int i = 0; i < l; i++)
	{
		char x = s[i];
		if(x == '1' || x == '2' || x == '3' || x == '4' || x == '5' || x == '6' || x == '7' || x == '8' || x == '9' || x == '0')
		{
//			cout << x << endl;
			a[cnt] = x - 48;
			cnt++;
		}
	} 
	sort(a + 1, a + 1 + cnt);
	for(int i = cnt; i > 1; i--)
	{
		cout << a[i];
	}
	return 0;
}
