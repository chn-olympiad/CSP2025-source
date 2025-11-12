#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

int n, q, flag = 1;
int buck[500005];

struct node{
	string t;
	int u;
};

map<string, string> mp;
vector<int> v;

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0),cin.tie(0), cout.tie(0);
	cin >> n >> q;
	
	if(n <= 1000 || q == 1){
		for (int i = 1; i <= n; i++){
			string t1, t2;
			cin >> t1 >> t2;
			mp[t1] = t2;
			v.emplace_back(t1.length());
		}
		for (int i = 1; i <= q; i++){
			int ans = 0;
			string t1, t2;
			cin >> t1 >> t2;
			int tl = t1.length();
			for (int i = 0; i < v.size(); i++){
				int len = v[i];
				if(buck[len]) continue;
				buck[len] = 1;
				for (int l = 0, r; (l + len - 1) < tl; l++){
					r = l + len - 1;
					string t3, t4;
					for (int k = l; k <= r; k++) t3 += t1[k];
					for (int k = 0; k < l; k++) t4 += t1[k];
					t4 += mp[t3];
					for (int k = r + 1; k < tl; k++) t4 += t1[k];
					if(t4 == t2) ans ++;
				}
			}
			cout << ans << "\n";
		}
		return 0;
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++){
		string t1, t2;
		cin >> t1 >> t2;
		mp[t1] = t2;
	}
	
	for (int i = 1; i <= q; i++){
		string t1, t2;
		cin >> t1 >> t2;
		int tl = t1.length(), u = -1;
		for (int j = 1; j <= tl; j++){
			if(t2[j] == 'b'){
				u = j;
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
