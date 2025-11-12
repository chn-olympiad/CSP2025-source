#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string s[n] = {},ss[q] = {};
	for(int i=0;i<n;i++)
	{
		cin >> s[i];
	}
	for(int i=0;i<q;i++)
	{
		cin >> ss[i];
	}
	cout << n-2 << endl << q-2 << endl;
	return 0;
 } 
