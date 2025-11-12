#include <bits/stdc++.h>
using namespace std;
int a[5005] = {};
bool used[5005] = {};
int n, ans=0;
vector<vector<int> > plans; 
void dfs(int len, vector<int> vec)
{
//	cout << "size" << vec.size();
	if (len == 0) {
		sort(vec.begin(), vec.end());
		int sum = 0;
		for (int i = 0; i < (int)vec.size(); i++) {
			sum += vec[i];
		}
		if (vec[vec.size()-1] * 2 < sum) {
//			cout << "Plan: ";
//			for (int i = 0; i < vec.size(); i++) {
//				cout << vec[i] << ' ';
//			}
//			cout << "\n";
			bool flag=1;
			for(int i = 0; i < (int)plans.size(); i++) {
				if(plans[i] == vec)
					flag=0;
			}
			if (flag==1) {
				plans.push_back(vec);
				ans++;
//				cout << "added\n";
			}
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (used[i] != true) {
			//cout << " i: " << i << " ai "<< a[i] << "\n";
			used[i] = true;
			vec.push_back(a[i]);
			len--;
//			cout << "vec ";
//			for (int i = 0; i < vec.size(); i++) {
//				cout << vec[i] << ' ';
//			}cout << " vecend\n";
			dfs(len, vec);
			len++;
			vec.pop_back();
			used[i] = false;
		}
	}
	return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
	}
	for (int i = 3; i <= n; i++) {
		vector<int> vec(0);
		dfs(i, vec);
	}
	cout << (ans % 998244353);
	return 0;
}
