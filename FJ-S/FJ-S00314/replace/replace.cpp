#include <bits/stdc++.h>
using namespace std;
string s[250001][5],t[250001][5];
int replace(string str,string str2,int x)
{
	int cnt=0;
	string ostr=str;
	for(int i=0;i<str.size();i++)
	{
		int sz=s[x][1].size();
		string newsub=str.substr(i,sz);
		if(newsub == s[x][1])
		{
			str.erase(str.begin()+i,str.begin()+i+sz);
			str.insert(i,s[x][2]);
			if(str == str2) cnt++;
			str=ostr;
		}
	}
	return cnt;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++) cin >> s[i][1] >> s[i][2];
	for(int i=1;i<=q;i++) cin >> t[i][1] >> t[i][2];
	int tot=0;
	for(int i=1;i<=q;i++)
	{
		tot=0;
		for(int j=1;j<=n;j++)
		{
			tot += replace(t[i][1],t[i][2],j);
		}
		cout << tot << endl;
	}
	return 0;
}