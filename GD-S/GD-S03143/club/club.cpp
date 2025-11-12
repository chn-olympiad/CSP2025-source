#include <cstdio>
#include <cctype>
#include <algorithm>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <utility>
using std::greater;
using std::sort;
using std::unordered_map;
typedef long long ll;
typedef __uint128_t u128;
typedef __int128_t i128;
typedef unsigned long long ull;
char *p1,*p2, buf[1<<20];
#define gc() (p1 == p2 && (p2 = (p1 = buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
template <typename T>
inline void read(T& cnt){
	cnt = 0;
	bool flag = 0;
	char c = getchar();
	for (;!isdigit(c);c = getchar())if (c == '-')flag = !flag;
	for (;isdigit(c);c = getchar())(cnt *= 10) += (c - 48);
}
//template <typename T>
//inline void write(T cnt){
//	if (cnt < 0){
//		putchar('-');
//		cnt = -cnt;
//	}
//	if (cnt > 9)write(cnt / 10);
//	putchar(cnt % 10 + 48);
//}
inline ll max(ll x,ll y){
	return x > y ? x : y;
}
inline ll min(ll x,ll y){
	return x > y ? y : x;
}
inline ll tre(ll x,ll y,ll z){
	return max(max(x,y),z);
}
#define fio(ifile,ofile) freopen(ifile,"r",stdin);freopen(ofile,"w",stdout);
const int N = 1e5 + 5;
ll T, n, ans, c1,c2,c3, s1,s2,s3,m1,m2,m3,minn,a[N],b[N],c[N];
double a1,a2,a3;
unordered_map <ll,ll> mp1, mp2, mp3;
unordered_map <ll,ll> mp4, mp5, mp6;
struct Node{
	ll a, b, c;
}node[N];
bool cmp(Node x,Node y){
	if (min(mp4[x.a],min(mp5[x.b],mp6[x.c])) == min(mp4[y.a],min(mp5[y.b],mp6[y.c])))
	return tre(mp1[x.a],mp2[x.b],mp3[x.c]) > tre(mp1[y.a],mp2[y.b],mp3[y.c]);
	return min(mp4[x.a],min(mp5[x.b],mp6[x.c])) < min(mp4[y.a],min(mp5[y.b],mp6[y.c])); 
}
void solve(){
	mp1.clear(),mp2.clear(),mp3.clear();
	ans = c1 = c2 = c3 = 0;
	s1 = s2 = s3 = 0;
	m1 = m2 = m3 = LLONG_MAX;
	read(n);
	for (int i = 1;i <= n;i++){
		read(a[i]),read(b[i]),read(c[i]);
		node[i].a = a[i],node[i].b = b[i],node[i].c = c[i];
	}
	sort (a + 1,a + 1 + n,greater<int>());
	sort (b + 1,b + 1 + n,greater<int>());
	sort (c + 1,c + 1 + n,greater<int>());
	for (int i = 1;i <= n;i++){
		mp4[a[i]] = i;
		mp5[b[i]] = i;
		mp6[c[i]] = i;
		if (a[i] == a[i-1] && i != 1);
		else mp1[a[i]] = abs(a[i]-a[i+1]);
		if (b[i] == b[i-1] && i != 1);
		else mp2[b[i]] = abs(b[i]-b[i+1]);
		if (c[i] == c[i-1] && i != 1);
		else mp3[a[i]] = abs(c[i]-c[i+1]);
	}
	for (int i = 1;i <= n;i++){
//		printf("%lld %lld %lld\n",mp1[node[i].a],mp2[node[i].b],mp3[node[i].c]);
	}
//	sort (node + 1,node + 1 + n);
//	minn = tre(s1-m1,s2-m2,s3-m3);
//	for (int i = 1;i <= n;i++){
//		node[i].a -= m1,node[i].b -= m2,node[i].c -= m3;
//		node[i].a += minn,node[i].b += minn,node[i].c += minn;
////		node[i].a = s1 - node[i].a, node[i].b = s2 - node[i].b, node[i].c = s3 - node[i].c;
//		printf("#%lld %lld %lld\n",node[i].a,node[i].b,node[i].c); 
//	}
	sort (node + 1,node + 1 + n, cmp);
	for (int i = 1;i <= n;i++){
		if (mp4[node[i].a] == mp5[node[i].b]){
			if (mp1[node[i].a] > mp2[node[i].b]){
				c1++;
				ans += (node[i].a);
			}else{
				c2++;
				ans += (node[i].b);
			}
		}else if (mp5[node[i].b] == mp6[node[i].c]){
			if (mp2[node[i].b] > mp3[node[i].c]){
				c2++;
				ans += (node[i].b);
			}else{
				c3++;
				ans += (node[i].c);
			}
		}else if (mp4[node[i].a] == mp6[node[i].c]){
			if (mp1[node[i].a] > mp3[node[i].c]){
				c1++;
				ans += (node[i].a);
			}else{
				c3++;
				ans += (node[i].c);
			}
		}else if (min(mp4[node[i].a],min(mp5[node[i].b],mp6[node[i].c])) == mp4[node[i].a] && (c1 < n/2)){
			c1++;
//			printf("@1\n");
			ans += (node[i].a);
		}else if (min(mp5[node[i].b],mp6[node[i].c]) == mp2[node[i].b] && (c2 < n/2)){
			c2++;
//			printf("@2\n");
			ans += (node[i].b);
		}else{
			c3++;
//			printf("@3\n");
			ans += (node[i].c);
		} 
	}
	printf("%lld\n",ans);
}
int main(){
	fio("club.in","club.out")
	read(T);
	while (T--)solve();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
