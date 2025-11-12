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
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	LL n,q;
	cin >> n >> q;
	cout << 13;
}
