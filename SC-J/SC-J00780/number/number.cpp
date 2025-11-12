#include <bits/stdc++.h>
using namespace std;
string s,w;
int n=0;
short a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			w+=s[i];
		}
	}
	cout<<w;
	return 0;
}