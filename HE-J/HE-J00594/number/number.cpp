#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fr(a,b,c) for(c=a;c<=b;c++)
#define rf(a,b,c) for(c=a;c>=b;c--)
#define I_AK_CSP 0
#define MAXN 1000001
string s;
ll n, book[MAXN], i, len;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	len = s.size();
	fr(0ll, len - 1, i)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			book[++n]=s[i] - '0';
		}
	}
	sort(book + 1, book + n + 1);
	rf(n, 1, i)
	{
		cout << book[i];
	}
	return I_AK_CSP;
}
