#include<bits/stdc++.h>
using namespace std;
struct str
{
	string s1,s2;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string str1,str2;
	cin>>n>>q;
	vector<str> v(n);
	for(auto& i:v)
		cin>>i.s1>>i.s2;
	cin>>str1>>str2;
	return 0;
}
