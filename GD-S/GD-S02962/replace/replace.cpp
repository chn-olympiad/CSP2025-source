#include <bits/stdc++.h>

using namespace std;
const int maxn = 200004;
int n, q;
unordered_map<string, string> mp;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for(int i=1;i<=n;i++)
	{
		string s, t;
		cin>>s>>t;
		mp[s] = t;
	}
	
	while(q--)
	{
		int ans = 0;
		string s, t;
		cin>>s>>t;
		for(int l=0;l<s.length();l++)
		{
			for(int r=l;r<s.length();r++)
			{
				// cout<<"[l, r] = "<<"["<<l<<", "<<r<<"]\n"; 
				string cur = "";
				for(int i=l;i<=r;i++) cur += s[i];
				// cout<<"cur: "<<cur<<endl;
				if(mp.find(cur) == mp.end()) continue;
				string t_cur = "";
				for(int i=l;i<=r;i++) t_cur += t[i];
				if(mp[cur] == t_cur)
				{
					string s_tmp = s;
					for(int i=l;i<=r;i++) s_tmp[i] = t[i];
					if(s_tmp == t) ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
 
