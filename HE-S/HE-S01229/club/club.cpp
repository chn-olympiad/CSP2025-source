#include <bits/stdc++.h>
using namespace std;
int n, t, ans, s1, s2, s3, k, p = 1, q = 1, aa, bb, cc;
int d[4];
struct node{
	int a, b, c, ma, mi, mid, c1, c2;
}s[100005];
bool cmp1(node x, node y){
	return x.c1 < y.c1;
}
bool cmp2(node x, node y){
	return x.c2 < y.c2;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n;
		k = n / 2;
		ans = 0, s1 = 0, s2 = 0, s3 = 0;
		for(int i = 1; i <= n; i++){
			cin >> aa >> bb >> cc;
			d[1] = aa, d[2] = bb, d[3] = cc;
			s[i].a = aa, s[i].b = bb, s[i].c = cc;
			sort(d + 1, d + 4);
			s[i].ma = d[3], s[i].mi = d[1], s[i].mid = d[2];
			s[i].c1 = s[i].ma - s[i].mid, s[i].c2 = s[i].mid - s[i].mi;
		}
		for(int i = 1; i <= n; i++){
			ans += s[i].ma;
			if(s[i].ma == s[i].a){
				s1++;
			}else if(s[i].ma == s[i].b){
				s2++;
			}else{
				s3++;
			}
		}
		sort(s + 1, s + n + 1, cmp1);
		for(int i = 1; i <= n;i++){
			if(s[i].ma == s[i].a){
				if(s1 > k){
					ans -= s[i].ma;
					s1--;
					ans += s[i].mid;
				}
			}else if(s[i].ma == s[i].b){
				if(s2 > k){
					ans -= s[i].ma;
					s2--;
					ans += s[i].mid;
				}
			}else{
				if(s3 > k){
					ans -= s[i].ma;
					s3--;
					ans += s[i].mid;
				}
			}
		}
		sort(s + 1, s + n + 1, cmp2);
		for(int i = 1; i <= n;i++){
			if(s[i].mid == s[i].a){
				if(s1 > k){
					ans -= s[i].mid;
					s1--;
					ans += s[i].mi;
				}
			}else if(s[i].mid == s[i].b){
				if(s2 > k){
					ans -= s[i].mid;
					s2--;
					ans += s[i].mi;
				}
			}else{
				if(s3 > k){
					ans -= s[i].mid;
					s3--;
					ans += s[i].mi;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
