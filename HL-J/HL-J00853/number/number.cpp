#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <cctype>
#include <cmath>
using namespace std;
string s,ans,p;
long long  cnt , f = 1000000000;
int maxx = 0;
int main ()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	cin >> s;
	long long len = s.size();
	for(int i = 0 ; i <= len - 1 ; i++)
	{
		if(islower(s[i]))
		{
			for(int j = i + 1 ; j <= s.size() ; j++)
			{
				s[i] = s[j];
			}
		}
	}
	for(int i = 0 ; i <= len ; i++)
	{
		if(isdigit(s[i]))   ans += s[i];
	} 
	long long llen = ans.size() ;
	for(int i= 1 ; i <= llen - 1 ; i++)
	{
		if(ans[i] < ans[i + 1])
		{
			int z  = ans[i];
			ans[i] = ans[i + 1];
			ans[i + 1] = z;
		}
	}
	
	cout << ans;
	return 0;
}
