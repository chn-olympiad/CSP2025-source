#include<bits/stdc++.h>
using namespace std;
//RP++
//I L ASCII(728383) F
const int N = 1e5 + 10;
int t, n, a[N][5], ans;
struct str{
	int d;
	bool operator<(const str b)const{
		return a[d][5] < a[b.d][5];
		// 按最大满意度与第二大满意度之差从小到大排序 
	}
};
vector<str> s[5];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		memset(a, 0, sizeof(a));
		s[1].clear(), s[2].clear(), s[3].clear();
		ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			int m = 0, p, sum = 0;
			// m 为最大满意度， p 为最满意部门 
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			for(int j = 1; j <= 3; j++){
				if(a[i][j] >= m){
					m = a[i][j];
					p = j;
				}
				sum += a[i][j];
			}
			a[i][4] = sum - m - min(a[i][1], min(a[i][2], a[i][3]));
			// 第二大满意度
			a[i][5] = m - a[i][4];
			// 最大满意度与第二大满意度之差
			str tmp;
			tmp.d = i;
			s[p].push_back(tmp);
			ans += a[i][p];
		}
		if(s[1].size() <= n/2 && s[2].size() <= n/2 && s[3].size() <= n/2){
			cout << ans << '\n';
			continue;
		}
		int x;
		for(int i = 1; i <= 3; i++){
			if(s[i].size() > n/2){
				x = i;
				break;
			}
		}
		int h = s[x].size() - n/2;
		sort(s[x].begin(), s[x].end());
		for(vector<str>::iterator it = s[x].begin(); it != s[x].end(); it++){
			if(h == 0) break;
			ans -= a[it -> d][5];
			h--;
		}
		cout << ans << '\n'; 
	}
	return 0;
}

