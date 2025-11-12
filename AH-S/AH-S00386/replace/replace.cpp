#include<bits/stdc++.h>
//僕的戦争
//Rastis!Rastis!Ra!Ti!Ti!Ti!Das!
//							——我是芙兰朵露小姐的血包

//（PS：这是我写得最认真的代码的说，其他都是暴力，虽然字符串哈希也算暴力就是了）
using namespace std;\
int n, q, len1, len2, maxlen2;
int slen[200001];
string s[2], t[2];
const int BASE = 131;
unsigned long long powtable[5000001] = {1};
unsigned long long HASHs[200001][2];
unsigned long long HASHt1[5000001], HASHt2;
unsigned long long subHASH, res, HASHDiff;
inline unsigned long long getHASHt1(int L, int R)
{
	if(L == 0)	return HASHt1[R];
	return HASHt1[R] - HASHt1[L - 1] * powtable[R - L + 1];
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[0] >> s[1];
		slen[i] = len1 = s[0].length();
		res = 0;
		for(int j = 0; j < len1; j++)
			res = res * BASE + s[0][j];
			//cout << "HASHs1[0~" << j << "] = " << res << "\n";
		HASHs[i][0] = res;
		res = 0;
		for(int j = 0; j < len1; j++)
			res = res * BASE + s[1][j];
			//cout << "HASHs2[0~" << j << "] = " << res << "\n";
		HASHs[i][1] = res;
	}
	while(q--)
	{
		cin >> t[0] >> t[1];
		len2 = t[0].length();
		if(len2 > maxlen2)
		{
			for(int i = maxlen2 + 1; i <= len2; i++)
				powtable[i] = powtable[i - 1] * BASE;
			maxlen2 = len2;
		}
		HASHt1[0] = t[0][0];
		HASHt2 = t[1][0];
		//cout << "HASHt1[0] = " << HASHt[0][0] << "\n";
		//cout << "HASHt2[0] = " << HASHt[1][0] << "\n";
		for(int i = 1; i < len2; i++)
		{
			HASHt1[i] = HASHt1[i - 1] * BASE + t[0][i];
			HASHt2 = HASHt2 * BASE + t[1][i];
			//cout << "HASHt1[0~" << i << "] = " << HASHt[0][i] << "\n";
			//cout << "HASHt2[0~" << i << "] = " << HASHt[1][i] << "\n";
		}
		res = 0;
		for(int i = 1; i <= n; i++)
		{
			HASHDiff = HASHt2 - HASHt1[len2 - 1];
			for(int j = 0; j + slen[i] - 1 < len2; j++)
				if(getHASHt1(j, j + slen[i] - 1) == HASHs[i][0])//成功匹配
					//cout << "OK,\"" << s[i][0] << "\" is founded in " << j << " of \"" << t[0] << "\"\n";
					if((HASHs[i][1] - getHASHt1(j, j + slen[i] - 1)) * powtable[len2 - j - slen[i]] == HASHDiff)res++;
		}
		cout << res << "\n";
	}
}
