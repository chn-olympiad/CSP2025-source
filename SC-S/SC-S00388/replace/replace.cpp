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
typedef unsigned long long ull;
#define fileio(i) freopen(i".in", "r", stdin), freopen(i".out", "w", stdout)
const int N = 2e5+4, L = 5e6+5;
const ull base = 31;
int n, q, ans;
struct node{
	ull hp, h1, h2;
	bool operator<(const node &other)const{
		return hp < other.hp;
	}
}a[N];
string s1, s2;
ull h1[L], h2[L], hp;
int main(){
	fileio("replace");
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i=1;i<=n;i++){
		cin >> s1 >> s2;
		if (s1==s2) continue;
		a[i].hp = a[i].h1 = a[i].h2 = 0;
		int j=0, l=s1.size()-1;
		while (j<s1.size()&&s1[j]==s2[j]) 
			++j;
		for (int k=j-1;k>=0;--k) {
			a[i].h1 = a[i].h1 * base + s1[k] - 'a'+1;
		}
		while (l>=0&&s1[l]==s2[l]) --l;
		for (int k=l+1;k<s1.size();++k) {
			a[i].h2 = a[i].h2 * base + s1[k] - 'a'+1;
		}
		for (int k=j;k<=l;++k){
			a[i].hp = a[i].hp * base + s1[k] - 'a' +1;
			a[i].hp = a[i].hp * base + s2[k] - 'a' +1;
		}
//		fprintf(stderr, "i=%d hp=%llu h1=%llu h2=%llu\n", i, a[i].hp, a[i].h1, a[i].h2);
	}
	sort(a+1, a+1+n);
	while (q--){
		ans = 0;
		cin >> s1 >> s2;
		if (s1.size()!=s2.size()) {
			cout << "0\n";
			continue;
		}
		hp = h1[0] = h2[0] = 0;
		int i=0, j=s1.size()-1, l, r;
		while (i<s1.size()&&s1[i]==s2[i]) ++i;
		for (int k=i-1;k>=0;--k) {
			h1[i-k] = h1[i-k-1] * base + s1[k] - 'a'+1;
//			fprintf(stderr, "i=%d h1=%llu\n", i-k, h1[i-k]);
		}
		sort(h1+1, h1+1+i);
		while (j>=0&&s1[j]==s2[j]) --j;
		for (int k=j+1;k<s1.size();++k) {
			h2[k-j] = h2[k-j-1] * base + s1[k] - 'a'+1;
//			fprintf(stderr, "i=%d h2=%llu\n", k-j, h2[k-j]);
		}
		sort(h2+1, h2+s1.size()-j);
		for (int k=i;k<=j;++k){
			hp = hp * base + s1[k] - 'a' +1;
			hp = hp * base + s2[k] - 'a' +1;
		}
		l = lower_bound(a+1, a+1+n, node{hp, 0, 0})-a;
		r = upper_bound(a+1, a+1+n, node{hp, 0, 0})-a;
//		fprintf(stderr, "l=%d r=%d\n", l, r);
		for (int k=l;k<r;++k){
			if ((!a[k].h1||*lower_bound(h1+1, h1+1+i, a[k].h1)==a[k].h1)&&(!a[k].h2||*lower_bound(h2+1, h2+s1.size()-j, a[k].h2)==a[k].h2)){
//				fprintf(stderr, "k=%d h1=%llu h2=%llu\n", k, a[k].h1, a[k].h2);
				++ans;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
