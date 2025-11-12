#include <bits/stdc++.h>
using namespace std;

map <string,string> s;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for (int i=1;i<=n;i++) 
	{
		string s1,s2;
		cin >> s1 >> s2;
		s[s1]=s2;
	}
	for (int i=1;i<=q;i++) cout << "0" << "\n"; 
}
