#include <bits/stdc++.h>
using namespace std;
string s;
int a[25];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(48<=s[i]&&s[i]<=57)
		{
			a[s[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(a[i]>0) for(int j=1;j<=a[i];j++) cout<<i;
	}
	return 0;
}
