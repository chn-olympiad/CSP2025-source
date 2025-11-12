#include <bits/stdc++.h>
using namespace std;

namespace solve{

struct Stu{
	int a1=0, a2=0, a3=0, amax=0;
	int& operator [](int i){
		switch (i){
			case 1: return a1;
			case 2: return a2;
			case 3: return a3;
			default: return amax;
		}
	}
	friend istream& operator >>(istream& is, Stu& stu){
		is >> stu[1] >> stu[2] >> stu[3];
		if (stu[1]>stu[2]) stu.amax = 1;
		else stu.amax = 2;
		return is;
	}
};

typedef long long LL;
void dfs(LL& ans, LL& temp, vector<int>& maxn, vector<Stu>& a, int n, int l, int now=1){
	if (now==n){
		for (int i=1;i<=3;i++){
			if (maxn[i]<l){
				temp += a[now][i];
				if (temp > ans) ans = temp;
				temp -= a[now][i];
			}
		}
	}
	for (int i=1;i<=3;i++){
		if (maxn[i]<l){
			temp += a[now][i];
			maxn[i]++;
			dfs(ans, temp, maxn, a, n, l, now+1);
			maxn[i]--;
			temp -= a[now][i];
		}
	}
}

void main(){
	int t;
	cin >> t;
	while (t--){
		bool B = true, A = true;
		int n;
		cin >> n;
		int limit = n >> 1;
		long long ans = 0, temp = 0;
		vector<Stu> a(n+1);
		for (int i=1;i<=n;i++){
			cin >> a[i];
			if (a[i][2]!=0) A = false;
			if (a[i][3]!=0) B = false, A = false;
		}
		if (A){
			sort(a.begin()+1, a.end(), [](Stu& s1, Stu& s2){
				return s1[1] > s2[1];
			});
			for (int i=1;i<=limit;i++) ans += a[i][1];
		} else if (B){
			sort(a.begin()+1, a.end(), [](Stu& s1, Stu& s2){
				return (s1[s1.amax]!=s2[s2.amax]) ? s1[s1.amax] > s2[s2.amax] :
						((s1[1]!=s2[1]) ? s1[1] > s2[1] : s1[2] < s2[2]);
			});
			vector<int> maxn(3, 0);
//			for (auto i: a){
//				cout << i[1] << " " << i[2] <<" "<<i.amax<< "\n";
//			}
			int i = 1;
			for (;;i++){
				Stu& stu = a[i];
				if (stu.amax == 0) continue;
				if (maxn[stu.amax]<limit){
					ans += stu[stu.amax];
					maxn[stu.amax]++;
				} else break;
			}
			if (maxn[1] == limit){
				sort(a.begin()+1+i, a.end(), [](Stu& s1, Stu& s2){
					return s1[2] > s2[2];
				});
				for (;i<=n;i++) ans += a[i][2];
			}
			if (maxn[2] == limit){
				sort(a.begin()+1+i, a.end(), [](Stu& s1, Stu& s2){
					return s1[1] > s2[1];
				});
				for (;i<=n;i++) ans += a[i][1];
			}
//			sort(a.begin()+1, a.end(), [](Stu& s1, Stu& s2){
//				return (s1[2]!=s2[2]) ? s1[2] > s2[2] : s1[1] < s2[1];
//			});
//			for (int i=1;i<=limit;i++) temp += a[i][2];
//			for (int i=limit+1;i<=n;i++) temp += a[i][1];
//			ans = max(temp, ans);
		} else{
//			if (n>10) continue;
	//		cout << "ok.\n";
			vector<int> maxn(4, 0);
			dfs(ans, temp, maxn, a, n, limit);
	//		ans = 0; temp = 0; a.clear(); maxn.clear();
		}
		cout << ans << "\n";
	}
}
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve::main();
	return 0;
}
