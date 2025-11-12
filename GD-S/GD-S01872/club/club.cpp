#include<bits/stdc++.h>
using namespace std;
const long long N = 500005;
long long n, T, ans, lena, lenb, lenc;
struct stu{
	long long a, b, c;
}s[N], aa[N], bb[N], cc[N];
long long maxx(long long a, long long b, long long c){return max(a, max(b, c));};
bool cmda(stu x, stu y){
	return x.a - max(x.b, x.c) < y.a - max(y.b, y.c);
}
bool cmdb(stu x, stu y){
	return x.b - max(x.a, x.c) < y.b - max(y.a, y.c);
}
bool cmdc(stu x, stu y){
	return x.c - max(x.b, x.a) < y.c - max(y.b, y.a);
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while(T--){
		ans = 0, lena = lenb = lenc = 0;
		cin >> n;
		for(long long i = 1;i <= n;i++){
			cin >> s[i].a >> s[i].b >> s[i].c;
			if(maxx(s[i].a, s[i].b, s[i].c) == s[i].a)aa[++lena] = s[i], ans += s[i].a;
			else if(maxx(s[i].a, s[i].b, s[i].c) == s[i].b)bb[++lenb] = s[i], ans += s[i].b;
			else if(maxx(s[i].a, s[i].b, s[i].c) == s[i].c)cc[++lenc] = s[i], ans += s[i].c;
		}
		if(lena > n / 2){
			sort(aa + 1, aa + 1 + lena, cmda);
			for(long long i = 1;i <= lena - n / 2;i++)ans += max(aa[i].b, aa[i].c) - aa[i].a;
		}
		if(lenb > n / 2){
			sort(bb + 1, bb + 1 + lenb, cmdb);
			for(long long i = 1;i <= lenb - n / 2;i++)ans += max(bb[i].a, bb[i].c) - bb[i].b;
		}
		if(lenc > n / 2){
			sort(cc + 1, cc + 1 + lenc, cmdc);
			for(long long i = 1;i <= lenc - n / 2;i++)ans += max(cc[i].b, cc[i].a) - cc[i].c;
		}
		cout << ans << '\n';
	}
	return 0;
}
