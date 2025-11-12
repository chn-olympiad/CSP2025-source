#include <bits/stdc++.h>
using namespace std;
string s;
int a[11];
int main()
{
	cin >> s;
	for(char c : s)
	{
		if(c>='0' && c<='9')
			a[c-'0']++;
	}
	for(int i=10;i>=0;i--)
	{
		while(a[i]--)
			printf("%d",i);
	}
	return 0;
}
