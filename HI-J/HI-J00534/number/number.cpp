#include <bits/stdc++.h>
using namespace std;
long long a[10000005],cnt;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
    if (s.size() == 1)
	{
		cout << s;
	}
	else if(s.size() > 1)
	{
		for (int i = 0;i <= s.size();i++)
	    {
		    if (s[i] >= '0' && s[i] <= '9')
		    {
			   a[i] += (s[i]-48);
			   cnt++;
			}	
	    }
	    sort(a,a+cnt+1);
	    for (int i = cnt;i > 0;i--)
	    {
	    	cout << a[i];
		}
	}
	return 0;
}

00
