#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N = 105;
inline ll read(){
	ll x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-')
		  f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}
inline void write(ll x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9)
	  write(x / 10);
	putchar(x % 10 + '0');
}
struct Node{
	int w, id;
	inline bool operator<(const Node&rhs)const{
		return w > rhs.w;
	}
}a[N];
int n, m, x, y;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n * m; ++i)
	  a[i] = {(int)read(), i};
	sort(a + 1, a + n * m + 1);
	x = 1, y = 1;
	for(int i = 1; i <= n * m; ++i){
		if(a[i].id == 1){
			write(x);
			putchar(' ');
			write(y);
			putchar('\n');
			return 0;
		}
		if(x & 1){
			if(y == n)
			  ++x;
			else
			  ++y;
		}
		else{
			if(y == 1)
			  ++x;
			else
			  --y;
		}
	}
	return 0;
}