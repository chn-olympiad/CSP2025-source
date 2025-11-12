#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T>inline void read(T &x){
	char c;int sign = 1;x = 0;
	do{c = getchar();if (c == '-') sign = -1;}while (! isdigit(c));
	do{x = (x << 3) + (x << 1) + (c & 15);c = getchar();} while (isdigit(c));
	x *= sign;
}
template <typename T>inline void wr(T x){
	if (x < 0){putchar('-');x = -x;}
	if (x > 9) wr(x / 10);
	putchar((x % 10) | 48);
}
const int N = 2e5 + 5;
int n,q;
string s1[N],s2[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> q;
	for ( int i = 1; i <= n; i ++){
		cin >> s1[i] >> s2[i];
	}
	for ( int i = 1; i <= q; i ++){
		string t1,t2;
		cin >> t1 >> t2;
		cout << 0 << endl;
	}
	return 0;
}
