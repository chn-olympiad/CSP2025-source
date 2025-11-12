#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
template <typename T> inline void read(T &x){
	x = 0;
	LL f = 1;
	char c = getchar();
	for(; !isdigit(c); c=getchar()) if(c == '-') f = -1;
	for(; isdigit(c); c=getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;
}
template <typename T> inline void print(T x){
	if(x < 0) x = -x,putchar('-');
	if(x > 9) print(x / 10);
	putchar(x % 10 + 48);
}
inline void sprint(const string s){
	for(auto x : s) putchar(x);
	return;
}
const int N = 1e2 + 11;
int n,m,k;
struct node{
	int num,id;
}a[N];
bool cmp(node x,node y){
	if(x.num > y.num) return 1;
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	read(n);read(m);
	k = n * m;
	for(int i=1;i<=k;i++){
		read(a[i].num);
		a[i].id = i;
	}
	sort(a + 1,a + 1 + k,cmp);
	int c = 1,l = 1,j = 1,id = 1;
	while(j <= k && a[j].id != 1){
		if(id == 1){
			l ++;
			if(l == n + 1){
				c ++;
				l --;
				id ^= 1;
			}
		}else{
			l --;
			if(l == 0){
				c ++;
				l ++;
				id ^= 1;
			}
		}
		j ++;
	}
	print(c);putchar(' ');print(l);
	return 0;
}
