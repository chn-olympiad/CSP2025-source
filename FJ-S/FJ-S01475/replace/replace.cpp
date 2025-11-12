#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
vector<string> s1,ss;
string s2,s3;
vector<vector<int>> k; 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	s1.resize(n + 1);ss.resize(n + 1);
	k.resize(n + 1);
	for(int i = 1;i <= n;++ i)
	{
		cin >> s1[i] >> ss[i];
		int len = s1[i].length();
		k[i].resize(len,0);
		for(int a = 1;a < len;++ a)
		{
			int j = k[i][a - 1];
			while(j > 0 && s1[i][a] != s1[i][j])j = k[i][j - 1];
			if(s1[i][a] == s1[i][j] && !(a == 1 && j == 0))
			{
				k[i][a] = j + 1;
			}
		}
	}
	for(int i = 1;i <= q;++ i)
	{
		cin >> s2 >> s3;
		ans = 0;
		for(int j = 1;j <= n;++ j)
		{
			int now = 0;
			for(int h = 0;h < s2.length();++ h)
			{
				while(now > 0 && s1[j][now] != s2[h])now = k[j][now];
				if(s1[j][now] == s2[h])
				{
					++ now;
					if(now == s1[j].length())
					{
//						cout << s2.substr(0,h + 1 - s1[j].length()) + ss[j] + s2.substr(h + 1,s2.length() - 1) << '\n';
						if(s2.substr(0,h + 1 - s1[j].length()) + ss[j] + s2.substr(h + 1,s2.length() - 1) == s3)++ ans;
						now = k[j][now - 1];
					}
				}
//				cout << now << ' '; 
			}
//			cout << '\n'; 
		}
		cout << ans << '\n';
	}
	return 0;
}

