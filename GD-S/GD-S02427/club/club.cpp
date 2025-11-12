#include <bits/stdc++.h>
using namespace std;
int T;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--){
		int n, ans;
		cin >> n;
		int m = n / 2;
		vector<int> a(n), b(n), c(n);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > q1;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > q2;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > q3;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < 3; j++){
				cin >> a[i] >> b[i] >> c[i];
				q1.push({a[i], i});
				q2.push({b[i], i});
				q3.push({c[i], i});
			}
		int v[3], p[500005];
		memset(p, 1, sizeof(p));
		for(int i = 0; i < n; i++){
			auto m1 = q1.top();
			auto m2 = q2.top();
			auto m3 = q3.top();
			q1.pop();
			q2.pop();
			q3.pop();
			cout << m1.first;
			if(m1.second == m2.second || m2.second == m3.second || m1.second == m3.second)
				if(m1.second == m2.second && m2.second == m3.second){
					if(v[1] > m && v[2] > m){
						ans += m3.first;
						v[3]++;
						p[m3.second]--;
					}
					if(v[3] > m && v[2] > m){
						ans += m1.first;
						v[1]++;
						p[m1.second]--;
					}
					if(v[1] > m && v[3] > m){
						ans += m2.first;
						v[2]++;
						p[m2.second]--;
					}
					else if(v[1] <= m && v[2] <= m && v[3] <= m){
						if(m1.first > m2.first){
							if(m1.first > m3.first){
								ans += m1.first;
								p[m1.second]--;
								v[1]++;
							}
							else{
								ans += m3.first;
								p[m3.second]--;
								v[3]++;
							}
						}
						else if(m1.first < m2.first){
							if(m2.first > m3.first){
								ans += m2.first;
								p[m2.second]--;
								v[2]++;
							}
							else{
								ans += m3.first;
								p[m3.second]--;
								v[3]++;
							}
						}
					}
					else{
						if(m1.first < m3.first){
							ans += m3.first;
							p[m3.second]--;
							v[3]++;
						}
						else{
							
						}
					}
				}
				else if(m1.second == m2.second && v[1] <= m && v[2] <= m && p[m1.second]){
					if(m1.first > m2.first){
						if(m1.first > m3.first){
							ans += m1.first;
							p[m1.second]--;
							v[1]++;
						}
						else{
							ans += m3.first;
							p[m3.second]--;
							v[3]++;
						}
					}
				}
			else{
				int n1 = max(m1.first, m2.first);
				n1 = max(n1, m3.first);
				ans += n1;
				if(n1 == m1.first){
					p[m1.second]--;
					v[1]++;
				}
				else if(n1 == m2.first){
					p[m2.second]--;
					v[2]++;
				}
				else{
					p[m3.second]--;
					v[3]++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
