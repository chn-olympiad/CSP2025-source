#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int _, n, a[N][3];
struct node {
	int c, id;
};

bool cmp (node x, node y){
	return x.c > y.c;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.in", "r", stdin);
	cin >> _;
	while (_--){
		cin >> n;
		vector <node> q1;
		vector <node> q2;
		vector <node> q3;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= 3; j++){
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= n; i++){
			int maxn = -1, id;
			for (int j = 1; j <= 3; j++){
				if (a[i][j] > maxn){
					maxn = a[i][j], id = j;
				}
			}
			if (id == 1){
				if (q1.size() < n / 2) q1.push_back({maxn, i});
				else {
					if (q1[q1.size() - 1].c < maxn || a[q1[q1.size() - 1].id][2] + maxn > q1[q1.size() - 1].c || a[q1[q1.size() - 1].id][3] + maxn > q1[q1.size() - 1].c){
						int wa = q1[q1.size() - 1].id;
						if (a[wa][2] > a[wa][3]) q2.push_back({a[wa][2], wa});
						else q3.push_back({a[wa][3], wa});
						q1.pop_back();
						q1.push_back({maxn, i});
					}
					else {
						if (a[i][2] > a[i][3]) q2.push_back({a[i][2], i});
						else q3.push_back({a[i][3], i});
					}
				}
			}
			else if (id == 2){
				if (q2.size() < n / 2) q2.push_back({maxn, i});
				else {
					if (q2[q2.size() - 1].c < maxn || a[q2[q2.size() - 1].id][1] + maxn > q2[q2.size() - 1].c || a[q2[q2.size() - 1].id][3] + maxn > q2[q2.size() - 1].c){
						int wa = q2[q2.size() - 1].id;
						if (a[wa][1] > a[wa][3]) q1.push_back({a[wa][1], i});
						else q3.push_back({a[wa][3], wa});
						q2.pop_back();
						q2.push_back({maxn, i});
					}
					else {
						if (a[i][1] > a[i][3]) q1.push_back({a[i][1], i});
						else q3.push_back({a[i][3], i});
					}
				}
			}
			else {
				if (q3.size() < n / 2) q3.push_back({maxn, i});
				else {
					if (q3[q3.size() - 1].c < maxn || a[q3[q3.size() - 1].id][2] + maxn > q3[q3.size() - 1].c || a[q3[q3.size() - 1].id][1] + maxn > q3[q3.size() - 1].c){
						int wa = q3[q3.size() - 1].id;
						if (a[wa][1] > a[wa][2]) q1.push_back({a[wa][1], wa});
						else q2.push_back({a[wa][2], wa});
						q3.pop_back();
						q3.push_back({maxn, i});
					}
					else {
						if (a[i][1] > a[i][2]) q1.push_back({a[i][1], i});
						else q2.push_back({a[i][2], i});
					}
				}
			}
			sort (q1.begin(), q1.end(), cmp);
			sort (q2.begin(), q2.end(), cmp);
			sort (q3.begin(), q3.end(), cmp);
		}
		ll ans = 0;
		for (int i = 0; i < q1.size(); i++) ans += q1[i].c;
		for (int i = 0; i < q2.size(); i++) ans += q2[i].c;
		for (int i = 0; i < q3.size(); i++) ans += q3[i].c;
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
