#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int n, q;
string s1[N], s2[N];
string t1[N], t2[N];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i ++)
	{
		cin >> s1[i] >> s2[i];
	}
	for(int i = 1;i <= q;i ++)
	{
		cin >> t1[i] >> t2[i];
		if(t1[i].length() != t2[i].length())
		{
			puts("0");
			continue;
		}
		int l = 0, r = n - 1;
		while(t1[i][l] == t2[i][l]) l ++; // 0~l-1
		while(t1[i][r] == t2[i][r]) r --; // r+1~n-1
		int cnt = 0;
		for(int j = 1;j <= n;j ++)
		{
			int st = 0;
			for(int k = max(0, r - (int)s1[j].length());k <= l;k ++)
			{
				int len = 0, flag = 0;
				while(len < s1[j].length() && t1[i][k + len] == s1[j][len] && s2[j][len] == t2[i][k + len])
					len ++;
				if(len == s1[j].length() && l + len > r) cnt ++;
			}
		}
		cout << cnt << endl;
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


3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
