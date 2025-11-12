#include<bits/stdc++.h>
using namespace std;
int s[10005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int x = 0;
	string a, b;
	cin >> a;
	for (int i = 0;i < a.length();i++)
	{
		if (a[i] >= '0' && a[i] <= '9')
		{
			b += a[i];
		}
	}
	for (int i = 0;i < b.length();i++)
	{
		if (b[i] == '0')
		{
			x += 1;
		}
	}
	for (int i = 0;i < b.length();i++)
	{
		s[i] = b[i] - '0';
	}
	for (int i = 1;i < b.length();i++)	
	{
		for (int j = 0;j < b.length()-i;j++)
	    {
			    
            if (s[j] < s[j+1])
		    {
			    int t = 0;
		        t = s[j];
			    s[j] = s[j+1];
			    s[j+1] = t;
	        }
	    }
    }

	for (int i = 0;i < b.length();i++)
	{
		cout << s[i];
	}
	
	return 0;
    
}

