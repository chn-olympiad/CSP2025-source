#include <bits/stdc++.h>
using namespace std;
    string s;
	int a[1000005]; 
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int k = 1;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] - '0' >= 1 && s[i] - '0' <= 9)
		{
		    a[k] = s[i] - '0';
		    k++;
		}
	}
	sort(a + 1, a + k, cmp);
	for(int i = 1; i < k; i++)
	    cout << a[i];
	return 0;
}
