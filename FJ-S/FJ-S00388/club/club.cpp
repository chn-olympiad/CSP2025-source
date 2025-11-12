#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct stu{
	long long g,f;
	bool operator < (const stu &s) const{
		return s.f > f;
	}
}stus[N];
long long T,n,a[N][3],g[N],cnt[3],res;
inline void solve(){
	cin >> n;
	res = cnt[0] = cnt[1] = cnt[2] = 0;
	for (int i = 1;i <= n;++i){
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]){
			if (a[i][1] >= a[i][2]) stus[i].f = a[i][0] - a[i][1]; 
			else stus[i].f = a[i][0] - a[i][2];
			++cnt[0],res += a[i][0],stus[i].g = 1;
		}else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]){
			if (a[i][0] >= a[i][2]) stus[i].f = a[i][1] - a[i][0];
			else stus[i].f = a[i][1] - a[i][2]; 
			++cnt[1],res += a[i][1],stus[i].g = 2;
		}else{
			if (a[i][0] >= a[i][1]) stus[i].f = a[i][2] - a[i][0];
			else stus[i].f = a[i][2] - a[i][1]; 
			++cnt[2],res += a[i][2],stus[i].g = 3;
		}
	}
	sort(stus + 1,stus + 1 + n);
	if (cnt[0] > n / 2){
		for (int i = 1;i <= n && cnt[0] > n / 2;++i) if (stus[i].g == 1) res -= stus[i].f,--cnt[0];
	}else if (cnt[1] > n / 2){
		for (int i = 1;i <= n && cnt[1] > n / 2;++i) if (stus[i].g == 2) res -= stus[i].f,--cnt[1];	
	}else{
		for (int i = 1;i <= n && cnt[2] > n / 2;++i) if (stus[i].g == 3) res -= stus[i].f,--cnt[2];
	}
	cout << res << "\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) solve();
	return 0;
}
