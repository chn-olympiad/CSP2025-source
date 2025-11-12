#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t, n, ans, sum, AD, BD;
ll ad[100005], bd[100005];
struct Cl{
	ll a[4];
}per[100005];
void FindAns(ll x, ll A, ll B, ll C, ll sum){
	if(A > n / 2 || B > n / 2 || C > n / 2) return;
	if(x > n){
		ans = max(ans, sum);
		return;
	}
	FindAns(x + 1, A + 1, B, C, sum + per[x].a[1]);
	FindAns(x + 1, A, B + 1, C, sum + per[x].a[2]);
	FindAns(x + 1, A, B, C + 1, sum + per[x].a[3]);
}
bool cmp(Cl a, Cl b){
	return a.a[1] > b.a[1];
}
bool cmA(ll a, ll b){
	return per[a].a[2] - per[a].a[1] > per[b].a[2] - per[b].a[1];
}
bool cmB(ll a, ll b){
	return per[a].a[1] - per[a].a[2] > per[b].a[1] - per[b].a[2];
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n;
		sum = ans = AD = BD = 0;
		ll mBx = 0, mCx = 0;
		for(int i = 1; i <= n; i++){
			cin >> per[i].a[1] >> per[i].a[2] >> per[i].a[3];
			mBx = max(mBx, per[i].a[2]);
			mCx = max(mCx, per[i].a[3]);
		}
		if(n <= 1){
			FindAns(1, 0, 0, 0, 0);
		}else if(mBx == 0 && mCx == 0){
			sort(per + 1, per + n + 1, cmp);
			for(int i = 1; i <= n / 2; i++){
				ans += per[i].a[1];
			}
		}else if(mCx == 0){
			for(int i = 1; i <= n; i++){
				if(per[i].a[1] >= per[i].a[2]){
					ad[++AD] = i;
					ans += per[i].a[1];
				}
				else{
					bd[++BD] = i;
					ans += per[i].a[2];
				}
			}
			if(AD > n / 2){
				sort(ad + 1, ad + AD + 1, cmA);
				ll i = 1;
				while(AD > n / 2){
					ans += per[ad[i]].a[2] - per[ad[i]].a[1];
					i++;
					AD--;
				}
			}else if(BD > n / 2){
				sort(bd + 1, bd + BD + 1, cmB);
				ll i = 1;
				while(BD > n / 2){
					ans += per[bd[i]].a[1] - per[bd[i]].a[2];
					i++;
					BD--;
				}
			}
		}cout << ans << '\n';
	}
	return 0;
}
//¿Õ¿Ç¶øÒÑ 
