#include <iostream>
#include <algorithm>
using namespace std;
void read(int &x){
	x = 0;
	int sign = 1;
	char c = getchar();
	while (!isdigit(c)){
		if(c == '-') sign = -1;
		c = getchar();
	} 
	while (isdigit(c)){
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	x *= sign;
}
char a[510];
int p[510], c[510];
const int mod = 998244353;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	read(n), read(m);
	scanf("%s", a + 1);
	bool spa = 1;
	for (int i = 1; i <= n; i ++ ) spa &= (a[i] == '1');
	for (int i = 1; i <= n; i ++ ) read(c[i]);
	long long res = 0;
	if(n <= 10){
		for (int i = 1; i <= n; i ++ ) p[i] = i;
		do{
			int fail = 0, cnt = 0;
			for (int i = 1; i <= n; i ++ ){
				int j = p[i];
				if(a[i] == '0' || fail >= c[j]) fail ++ ;
				else cnt ++ ;
//				cout << j << ' ' << fail << ' ' << cnt << '\n';
			}
//			puts("");
			if(cnt >= m) res ++ ;
		}while (next_permutation(p + 1, p + n + 1));
		cout << res << '\n';
	}
	return 0;
} 
