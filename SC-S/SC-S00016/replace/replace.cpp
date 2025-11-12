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
LL n,q;
map<string,string> mp;
set<string> s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n);read(q);
	for(LL i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1] = s2;
	}
	while(q --){
		s.clear();
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size() != s2.size()){
			print(0);
			putchar('\n');
			continue;
		}
		LL n = s1.size(),cnt = 0;
		for(LL i=0;i<=n;i++){
			for(LL j=i;i+j<=n;j++){
				string pt = s1.substr(i,j - i + 1),pt2 = s2.substr(i,j - i + 1);
				string l1 = s1.substr(0,max(i,0LL)),l2 = s2.substr(0,max(i,0LL));
				string r1 = s1.substr(min(j + 1,n)),r2 = s2.substr(min(j + 1,n));
				if(mp[pt] == pt2 && l1 == l2 && r1 == r2) s.insert(pt);
			}
		}
		cnt = s.size();
		print(cnt);
		putchar('\n');
	}
	return 0;
}
