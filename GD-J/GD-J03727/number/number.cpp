#include<bits/stdc++.h> 
using namespace std;
const int maxn = 1e6 + 10;
int c,num,b[maxn];
int z(int a) {
	int sum = 1;
	for (int i = 0;i < a;i++) {
		sum *= 10;
	}
	return sum;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a;
	cin >> s;
	for (int i = 0;i < s.size();i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			b[i] += s[i] - '0' + 1;
		}
	}
	for(int i = 0;i < a.size();i++) {
		b[i] = a[i] - '0' + 1;
	}
	sort(b,b + a.size());
	for (int i = 0;i < a.size();i++) {
		if (i == 0) num += b[0];
		num = num + b[i] * z(i);
	} 
	cout << num;
	return 0;
}
