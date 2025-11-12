#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;

string s;
int num[maxn];
int n = 0;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0;i <= (int)s.size();i ++) 
		if (s[i] >= '0' && s[i] <= '9') 
			num[++ n] = s[i] - '0';
	sort(num + 1, num + n + 1);
	for (int i = n;i >= 1;i --) printf("%d", num[i]);
	return 0;
}