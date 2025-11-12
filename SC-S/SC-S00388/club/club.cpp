#include <bits/stdc++.h>
#if __linux__
#define ge getchar_unlocked
#define pu putchar_unlocked
#else
#define ge getchar
#define pu putchar
#endif
using namespace std;
typedef long long ll;
char ch;
template <typename T>
inline void read(T &x){
	x=0;bool sgn=0;
	while ('0'>ch||ch>'9') ch=ge(), sgn |= ch=='-';
	while ('0'<=ch&&ch<='9') x=x*10+ch-'0', ch=ge();
	if (sgn) x=-x;
}
template <typename T>
inline void write(T x){
	if (x<0) pu('-'), x=-x;
	static int sta[110], top = 0;
	do sta[top++] = x%10, x/=10; while (x);
	while (top) pu(sta[--top]+'0');
}
#define fileio(i) freopen(i".in", "r", stdin), freopen(i".out", "w", stdout)
const int N = 1e5+4;
int t, n, cntx, cnty, cntz;
ll ans;
struct node{
	int x, y, z, c;
	bool operator<(const node&other){
		if (c!=1) return 0;
		if (other.c!=1) return 1;
		return x-max(y, z)<other.x-max(other.y, other.z);
	}
}a[N];
void solve(){
	read(n);
	cntx = cnty = cntz = ans = 0;
	for (int i=1;i<=n;i++) {
		read(a[i].x), read(a[i].y), read(a[i].z);
		if (a[i].x>=a[i].y){
			if (a[i].x>=a[i].z) ++cntx, ans += a[i].x, a[i].c = 1;
			else ++cntz, ans += a[i].z, a[i].c = 3;
		}
		else {
			if (a[i].y>=a[i].z) ++cnty, ans += a[i].y, a[i].c = 2;
			else ++cntz, ans += a[i].z, a[i].c = 3;
		}
	}
	if (cnty>n/2){
		swap(cntx, cnty);
		for (int i=1;i<=n;i++) {
			if (a[i].c!=3) a[i].c = 3-a[i].c;
			swap(a[i].x, a[i].y);
		}
	}
	else if (cntz>n/2){
		swap(cntx, cntz);
		for (int i=1;i<=n;i++) {
			a[i].c = 4-a[i].c;
			swap(a[i].x, a[i].z);
		}
	}
	if (cntx<=n/2) return write(ans), pu(10), void();
	sort(a+1, a+1+n);
	for (int i=1;i<=cntx-n/2;++i) ans -= a[i].x-max(a[i].y, a[i].z);
	write(ans), pu(10);
}
int main(){
	fileio("club");
	read(t);
	while (t--) solve();
	return 0;
}
