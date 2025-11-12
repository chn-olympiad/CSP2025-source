#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int cnt[10];
signed main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(auto c : s)if(isdigit(c))cnt[c - '0']++; 
	for(int i = 9; i >= 0; i--)while(cnt[i]--)cout << (char)('0' + i);
	return 0;
}
/*
Record

2025-11-1 8:37 Pass T1

Solution
开一个桶记录一下数字即可，O(n)

Note
Nothing Here 
*/ 