#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL ans = 0;
struct student{
	LL a1, a2, a3;//di n zhi yuan
	LL g1, g2, g3;
};
LL t, n;
student a[1000100];
LL cnt[5];
int cmp(student a, student b){
	if(a.a1 - a.a2 != b.a1 - b.a2){
		return a.a1 - a.a2 > b.a1 - b.a2;
	}else{
		return a.a1 > b.a1;
	}
	
}
int cmp2(student a, student b){
	return a.a2 > b.a2;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for(LL k = 1; k <= t; k++){
		cin >> n;
		for(LL i = 1; i <= n; i++){
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			a[i].g1 = 1;
			a[i].g2 = 2;
			a[i].g3 = 3;
			if(a[i].a1 < a[i].a2){
				swap(a[i].a1, a[i].a2);
				swap(a[i].g1, a[i].g2);
			}
			if(a[i].a2 < a[i].a3){
				swap(a[i].a2, a[i].a3);
				swap(a[i].g1, a[i].g2);
			}
			if(a[i].a1 < a[i].a2){
				swap(a[i].a1, a[i].a2);
				swap(a[i].g1, a[i].g2);
			}
			a[i].a1 -= a[i].a3;
			a[i].a2 -= a[i].a3;
			ans += a[i].a3;
		}
		LL pos = 0;
		sort(a + 1, a + n + 1, cmp);
		for(int i = 1; i <= n; i++){//di yi zhi yuan
			if(cnt[a[i].g1] + 1 <= n / 2){
				cnt[a[i].g1]++;
				ans += a[i].a1;
			}else{
				pos++;
				a[pos].g1 = a[i].g1;
				a[pos].g2 = a[i].g2;
				a[pos].g3 = a[i].g3;
				a[pos].a1 = a[i].a1;
				a[pos].a2 = a[i].a2;
				a[pos].a3 = a[i].a3;
			}
		}
		sort(a + 1, a + pos + 1, cmp2);
		for(int i = 1; i <= pos; i++){//di er zhi yuan
			if(cnt[a[i].g2] + 1 <= n / 2){
				cnt[a[i].g2]++;
				ans += a[i].a2;
			}
		}
		cout << ans << '\n';
	}
	
	
	return 0;
 } 
