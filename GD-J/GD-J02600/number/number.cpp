#include<bits/stdc++.h>
using namespace std;
char a[9];
int main()
{
	string s;
	cin>>s;

	for(int i=0;i<s.size;i++)
	{
		if('0'<=s[i]&&s[i]<='9')
			a[s[i]-'0']++;
	}
	return 0;
}
