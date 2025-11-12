#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

string back[5000005];
int n,cnt=0;
struct node
{
	int ch[26];
	bool end;
	string rep;
} trie[5000005];
inline void build(string s,string t)
{
	int root=0;
	for (auto c:s)
	{
		c-='a';
		if (!trie[root].ch[c]) trie[root].ch[c]=++cnt;
		root=trie[root].ch[c]; 
	}
	trie[root].end=1,trie[root].rep=t;
}
inline string find(string s)
{
	int root=0;
	for (auto c:s)
	{
		c-='a';
		if (!trie[root].ch[c]) return "";
		root=trie[root].ch[c];
	}
	if (!trie[root].end) return "";
	return trie[root].rep;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int q;
	cin >> n >> q;
	string s,t;
	for (int i=1;i<=n;i++)
	{
		cin >> s >> t;
		build(s,t);
	}
	while (q--)
	{
		cin >> s >> t;
		back[t.size()]="";
		for (int i=s.size()-1;i>=0;i--)
			back[i]=s[i]+back[i+1];
		vector<pair<string,string> > v;
		string now="";
		int ans=0;
		for (int i=0;i<s.size();i++)
		{
			v.push_back({"",now});
			for (auto &V:v) V.first+=s[i];
			for (auto &str:v)
			{
				string res=find(str.first);
				if (res!="" && str.second+res+back[i+1]==t)
					ans++;
			}
			now+=s[i];
		}
		cout << ans << endl;
	}
	return 0;
}
