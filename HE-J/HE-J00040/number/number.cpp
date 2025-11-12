#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a,b;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			a+=s[i];
	int x=a.size();
	for(int i=0;i<x;i++)
		sort(a.begin(),a.end());
	for(int i=0;i<x;i++)
		b+=a[i];
	for(int i=x-1;i>-1;i--)
		cout<<b[i];
	return 0;
}
