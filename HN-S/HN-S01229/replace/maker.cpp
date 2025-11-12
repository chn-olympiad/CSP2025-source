#include<bits/stdc++.h>
using namespace std;
mt19937 rd(time(0));
signed main()
{
	freopen("replace.in","w",stdout);
	int n,q,L;
	n=2e5;q=1e5,L=5e6;
	cout<<n<<' '<<q<<'\n';
	for(int i=1;i<=n;i++)
	{
		string s="";
		for(int j=0;j<7;j++)
		s+=char(rd()%26+'a');
		s[4]='l';
		cout<<s<<' ';
		s[4]='f';
		cout<<s<<'\n';
	}
	for(int i=1;i<=q;i++)
	{
		string s;
		for(int j=0;j<25;j++)
		s+=char(rd()%26+'a');
		s[13]='l';
		cout<<s<<' ';
		s[13]='f';
		cout<<s<<'\n';
	}
	return 0;
}