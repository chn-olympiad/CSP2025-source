#include <bits/stdc++.h>
using namespace std;
int n,cnt[4],t,m;
long long ans;
struct ppp{
	long long z;
	int id;
}a[100005][4];
bool cmp(ppp xxx,ppp yyy){
	return xxx.z > yyy.z;
}
priority_queue<long long,vector<long long>,greater<long long> >q[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		m = (n>>1);
		while(cnt[1] > 0) q[1].pop(),--cnt[1];
		while(cnt[2] > 0) q[2].pop(),--cnt[2];
		while(cnt[3] > 0) q[3].pop(),--cnt[3];
		ans = 0;
		for(int i = 1;i <= n;++i) cin >> a[i][1].z >> a[i][2].z >> a[i][3].z;
		for(int i = 1;i <= n;++i) a[i][1].id = 1,a[i][2].id = 2,a[i][3].id = 3;
		for(int i = 1;i <= n;++i){
			sort(a[i]+1,a[i]+4,cmp);
			q[a[i][1].id].push(a[i][1].z - a[i][2].z),ans += a[i][1].z,++cnt[a[i][1].id];
		}
		while(cnt[1] > m) ans -= q[1].top(),q[1].pop(),--cnt[1];
		while(cnt[2] > m) ans -= q[2].top(),q[2].pop(),--cnt[2];
		while(cnt[3] > m) ans -= q[3].top(),q[3].pop(),--cnt[3];
		cout << ans << "\n";
	}
	return 0;
}
