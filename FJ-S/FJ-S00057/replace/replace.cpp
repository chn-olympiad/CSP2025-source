#include<bits/stdc++.h>
using namespace std;
struct str2
{
	string s1;
	string s2;
};
bool findson(const string &fa, const string &son, const int begin)
{
	for(size_t i = begin, j = 0; j < son.size();i++, j++)
		if(fa[i] != son[j])
			return false;
	return true;
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,p;
	cin >> n >> p;
	vector<str2> s(n);
	vector<str2> t(p);
	for(int i = 0;i < n; i++)
		cin >> s[i].s1 >> s[i].s2;
	for(int i = 0;i < p; i++)
		cin >> t[i].s1 >> t[i].s2;
	for(int i = 0;i < p; i++)
	{
		long long ans = 0;
		for(int j = 0; j < n; j++)
		{
			vector<int> finded_place;
			for(size_t l1 = 0; l1 + s[j].s1.size() <= t[i].s1.size(); l1++)
			{
				if(findson(t[i].s1, s[j].s1, l1))
					finded_place.push_back(l1);
			}
			for(size_t l = 0; l < finded_place.size(); l++)
			{
				string temp = t[i].s1;
				temp.replace(finded_place[l], s[j].s1.size(), s[j].s1);
				if(temp == t[i].s2)
					ans++;
			}
		}
		cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
