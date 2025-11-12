#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 10000;
string s;
long long vis[MAXN];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (long long i = 0;i < s.size();i ++){
		if (isdigit(s[i])){
			vis[s[i] - '0'] ++;
		}
	}
	for (long long i = 9;i >= 0;i --){
		while (vis[i]){
			vis[i] --;
			cout << i;
		}
	}
	cout << endl;
	return 0;
}