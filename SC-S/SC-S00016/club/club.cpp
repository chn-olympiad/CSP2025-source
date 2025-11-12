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
const int N = 1e5 + 11;
LL t,n,ans,cnt1,cnt2;
struct node{
	LL x,y,z;
}a[N];
int dp[N][5];
void dfs(LL id,LL c1,LL c2,LL c3,LL tot){
	if(id == n + 1){
		ans = max(ans,tot);
		return;
	}
	if(c1 + 1 <= n / 2) dfs(id + 1,c1 + 1,c2,c3,tot + a[id].x);
	if(c2 + 1 <= n / 2) dfs(id + 1,c1,c2 + 1,c3,tot + a[id].y);
	if(c3 + 1 <= n / 2) dfs(id + 1,c1,c2,c3 + 1,tot + a[id].z);
}
bool cmp(node x,node y){
	if(x.x > y.x) return 1;
	return 0;
}
bool cmp2(node x,node y){
	if(abs(x.x - x.y) > abs(y.x - y.y)) return 1;
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(t);
	while(t --){
		ans = cnt1 = cnt2 = 0;
		read(n);
		for(LL i=1;i<=n;i++){
			read(a[i].x);read(a[i].y);read(a[i].z);
			if(a[i].y == 0 && a[i].z == 0) cnt1 ++;
			if(a[i].z == 0) cnt2 ++;
		}
		if(cnt1 == n){
			sort(a + 1,a + 1 + n,cmp);
			LL tot = 0;
			for(LL i=1;i<=n/2;i++) tot += a[i].x;
			print(tot);
			putchar('\n');
			continue;
		}
		if(cnt2 == n){
			sort(a + 1,a + 1 + n,cmp2);
			LL c1 = 0,c2 = 0,tot = 0;
			for(LL i=1;i<=n;i++){
				if(c1 == n / 2){
					tot += a[i].y;
					continue;
				}else if(c2 == n / 2){
					tot += a[i].x;
					continue;
				}
				if(a[i].x > a[i].y){
					c1 ++;
					tot += a[i].x;
				}else{
					c2 ++;
					tot += a[i].y;
				}
			}
			print(tot);
			putchar('\n');
			continue;
		}
		dfs(1,0,0,0,0);
		print(ans);
		putchar('\n');
	} 	
	return 0;
}