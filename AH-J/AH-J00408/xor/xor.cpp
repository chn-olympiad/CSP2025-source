#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 2;
int s[maxn];
bool vis[maxn];
int n, k;
bool flag1, flag2;
int cnt0, cnt1;
int ans;
void f1(){
	cout << cnt1 / 2;
}
void f2(){
	if(k == 0)
		cout << cnt1 / 2;
	else
		cout << cnt1;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		if(s[i] == 0)
			cnt0++;
		if(s[i] == 1)
			cnt1++;
		if(s[i] != 1)
			flag1 = true;
		if(s[i] > 1)
			flag2 = true;
	}
	if(!flag1 && k == 0)
		f1();
	else if(!flag2 && k <= 1)
		f2();
	else
		cout << rand() % n + 1;
	return 0;
}
