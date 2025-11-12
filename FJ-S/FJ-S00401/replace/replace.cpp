#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 5e6 + 10;

int n, q;
string str1[N], str2[N];
map<pair<string, string>, int> hash1;

signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int j = 1 ; j <= n ; j ++ ) 
	{
		string op1, op2;
		cin >> str1[j] >> str2[j];
	}
	for(int cases = 1 ; cases <= q ; cases ++ )
	{
		string op1, op2;
		cin >> op1 >> op2;
		if(op1.size() != op2.size())
		{
			cout << "0\n";
			continue;
		}
		int ls = -1, rs = -1;
		for(int i = 0 ; i < op1.size() ; i ++ )
			if(op1[i] != op2[i])
			{
				ls = i;
				break;
			}
		for(int i = op2.size() - 1; i >= 0 ; i -- )
			if(op1[i] != op2[i])
			{
				rs = i;
				break;
			}
		string Str1, Str2;
		for(int i = ls ; i <= rs ; i ++ )
		{
			Str1 += op1[i];
			Str2 += op2[i];
		}
		int cnt = 0;
//		cout << cases << ": \n";
		for(int i = 1 ; i <= n ; i ++ )
		{
			int tmp1 = str1[i].find(Str1);
			if(tmp1 >= str1[i].size()) continue;
			int tmp2 = str2[i].find(Str2);
			if(tmp2 >= str2[i].size()) continue;
			int Tmp1 =  op1   .find(str1[i]);
			if(Tmp1 >=  op1   .size()) continue;
			int Tmp2 =  op2   .find(str2[i]);
			if(Tmp2 >=  op2   .size()) continue;
//			cout << i << ": ";
//			cout << tmp1 << " " << tmp2 << " " << Tmp1 << " " << Tmp2 << endl;
			if(tmp1 != tmp2) continue;
			if(Tmp1 != Tmp2) continue;
			cnt ++ ;
		}
		cout << cnt << endl;
//			if(str1[i].find(Str1) <= str1[i].size() && str2[i].find(Str2) <= str2[i].size() && op1.find(str))
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
