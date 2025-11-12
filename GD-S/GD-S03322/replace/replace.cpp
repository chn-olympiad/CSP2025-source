#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int G, n, m, ans=0, cnt=0;
string a[N], a2[N], s, s2;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	scanf("%d%d", &n, &G);
	for (int i=1; i<=n; i++) cin>>a[i]>>a2[i];
	while (G--)
	{
		string pre="", pre2="";
		ans=0, cnt=0;
		
		cin>>s>>s2;
		for (int i=0; i<s.size(); i++)
		{
			for (int j=1; j<=n; j++)
			{
				if (s.substr(i, a[j].size())!=a[j]) continue;
//				printf("{%d %d}\n", i, j);
				string nw=pre+a2[j]+s.substr(i+a2[j].size(), s.size()-(i+a2[j].size())+1);
				if (nw==s2) ans++;
			}
			pre+=s[i], pre2+=s2[i];
			if (pre!=pre2) cnt++;
			if (cnt>=2) break;
		}
		
		printf("%d\n", ans);
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb



*/
