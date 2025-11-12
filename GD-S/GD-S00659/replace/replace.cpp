#include<unordered_map>
#include<iostream>
#include<cstdio>
using namespace std;
const int N = 2e5 + 10;
int n,q,ans;
string q1,q2,s1[N],s2[N];
unordered_map <string,bool> vis;
void dfs(string now)
{
	for(int i = 0;i < now.size();i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(s1[j] == s2[j])
				continue;
			string tmp = now.substr(i,s1[j].size());
			if(tmp.size() != s1[j].size())
				continue;
			if(tmp == s1[j])
			{
				tmp = now.substr(0,i) + s2[j] + now.substr(i + s1[j].size());
				if(tmp == q2)
					ans++;
			}
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
		cin >> s1[i] >> s2[i];
	while(q--)
	{
		ans = 0;
		cin >> q1 >> q2;
		dfs(q1);
		cout << ans << '\n';
	}
	return 0;
}

