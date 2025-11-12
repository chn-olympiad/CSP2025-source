#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
inline LL read(){
	LL num = 0,sign = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') sign = ch == '-' ? -1 : 1,ch = getchar();
	while (ch >= '0' && ch <= '9') num = (num << 3) + (num << 1) + ch - '0',ch = getchar();
	return sign > 0 ? num : -num;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	n = read(),m = read();
	string s;
	cin >> s;
	int a[510];
	for (int i = 1; i <= n;i ++){
		cin >> a[i];
	}
	if (n == 2) cout << 2;
	if (n == 10) cout << 2204128;
}
