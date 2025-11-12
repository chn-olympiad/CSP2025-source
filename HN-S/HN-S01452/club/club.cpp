#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 10;
#define int long long
struct jgt{
	int a, b, c, maxn, cha;
}s[N],a[N],b[N],c[N];
bool cmp(jgt a, jgt b){
	return a.cha < b.cha;
}
int bj[10];
int zws12(int a, int b, int c){
	bj[1] = a, bj[2] = b, bj[3] = c;
	sort(bj + 1, bj + 4);
	return bj[2];
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		int n, ans = 0, ta = 0, tb = 0, tc = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> s[i].a >> s[i].b >> s[i].c;
			int maxn = max(s[i].a, max(s[i].b, s[i].c));
			int mid = zws12(s[i].a, s[i].b, s[i].c);
			int cha = maxn - mid;
			//cout << s[i].a << " b = " << s[i].b << " c = " << s[i].c << " maxn = " << maxn << " cha = " << cha << endl;
			s[i].cha = cha; s[i].maxn = maxn;
			if(maxn == s[i].a) a[++ta] = s[i];
			else if(maxn == s[i].b) b[++tb] = s[i];
			else if(maxn == s[i].c) c[++tc] = s[i];
			ans += maxn;  
		}
		int x = n / 2;
		//cout << "ta = " << ta << " tb = " << tb << " tc = " << tc << " ans = " << ans << endl;
		if(ta > x) {
			sort(a + 1, a + ta + 1, cmp);
			for(int i = 1; i <= ta - x; i++) {
				ans -= a[i].cha;
				//cout << a[i].maxn << " cha = " << a[i].cha << endl;
			}	
		}else if(tb > x){
			sort(b + 1, b + tb + 1, cmp);
			for(int i = 1; i <= tb - x; i++) {
				ans -= b[i].cha;
				//cout << b[i].maxn << " cha = " << b[i].cha << endl;
			}
		}else if(tc > x){
			sort(c + 1, c + tc + 1, cmp);
			for(int i = 1; i <= tc; i++){
				//cout << "ÓÐ " << c[i].maxn << " cha = " << c[i].cha << endl; 
			}
			for(int i = 1; i <= tc - x; i++) {
				ans -= c[i].cha;
				//cout << c[i].maxn << " cha = " << c[i].cha << " ÐÂ ans = " << ans << endl;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
