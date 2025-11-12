#include<bits/stdc++.h>
#define ll long long
#define Int __int128
#define pb push_back
using namespace std;
const int maxn = 1e6+5;
int n;
string s;
vector<int>v;
signed main()
{
//	freopen("number.in" , "r" , stdin);
//	freopen("number.out" , "w" , stdout);
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++) if (isdigit(s[i]))v.pb(s[i]^48);
	sort(v.begin(),v.end(),greater<int>());
	for (auto x : v)cout << x;
	return 0;
}

/*
mem file time
author: YBTL sjwhsss RP++

我常常追忆过去。
中间忘了。
后面忘了。
已完成今日
嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟
嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟
嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟嘟
大学习。
*/