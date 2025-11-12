#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin>>s;
	for (int i=0;s.size();i++)
	    if (s[i]<='9' && s[i]>=0)
	        cout<<s[i];
	return 0;
}
