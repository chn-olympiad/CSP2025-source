#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	int a[100005], n = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			s[i] -= '0';
			a[n] = s[i];
			n++;
		}
	}
    for (int i = n - 1; i >= 0; i--)
    {
	    for (int j = 0; j < i; j++)
        {
	    	if (a[j] < a[j + 1])
		    {
		    	int x = a[j];
		    	a[j] = a[j + 1];
		    	a[j + 1] = x;
		    }
     	} 
    }
	for (int i = 0; i < n; i++)
	    cout << a[i];
	return 0;
}
