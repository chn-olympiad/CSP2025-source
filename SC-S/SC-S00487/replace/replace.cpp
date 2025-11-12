#include<bits/stdc++.h>
#define ll long long
#define furina puts("QAQ");
using namespace std;
const int maxn = 5e5 + 5;

int n, q;
string s1[maxn], s2[maxn];
string t1, t2;
//string

signed main()
{
//	system("fc");
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> s1[i] >> s2[i];
	}
	
//	cout << s2[1][0] << '\n';	
	
	for (int num = 1; num <= q; num++)
	{
		int ans = 0;
		string s;
		
		cin >> t1 >> t2;
		
		s = t1;
//		cout << s << '\n';
		
		int len1 = t1.length();
		int len2 = t2.length();
		
		for (int i = 0; i < len1; i++)
		{
			s = t1;
						
			for (int j = 1; j <= n; j++)
			{
				int len = s1[j].length();
				
				if (i + len > len1 || i + len > len2) continue;
				
				for (int k = i; k < i + len; k++)
				{
					if (s[k] == s1[j][k - i])
					{
						s[k] = s2[j][k - i];
//						cout << s << '\n';
					}
					else
					{
						s = t1;
						break;
					}
				}
				if (s == t2)
				{
//					cout << j <<  '\n';
					ans++;
					s = t1;
				}
			}
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
//啊啊啊啊啊啊啊 初音未来好可爱 
//我亲爱的 Miku 会保佑我不挂分的
//啊    ~音门永恒~
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/ 