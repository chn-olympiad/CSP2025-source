#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005];
long long n = 0 , m = 0;
long long ans = 0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin >> s;
    for (int i = 0; i <= s.length();i++)
    {
    	if (s[i] >= 0 && s[i] <= 9)
    	{
    		cout << s[i];
		}
	}
	return 0;
 } 
