#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
struct lu{
	int ans = 0;
	vector<string> vs;
	void add(string s){
		bool flag = false;
		for (string x : vs){
			int answer = 0;
			int len1 = x.size(), len2 = s.size();
			if (len1 != len2) continue;
			for (int i=0; i<len1; i++) {
				for (int j=0; j<len2; j++){
					if (x[i] == s[j]) {
						answer ++;
						break;
					}
				}
			}
			if (answer == len2){
				flag = true;
				break;
			}
		}
		if (flag) return;
		vs.push_back(s);
		ans ++;
		ans = ans % 998244353;
	}
} ans;
string exam;
int c[501];
void onExam(vector<int> order) {
	vector<int> p;
	for (int x : order) {
		p.push_back(c[x]);
	}
	int people = 0;
	string ren;
	int slen = exam.size(), vlen = p.size();
	for (int i=0; i<slen; i++) {
		if (exam[i] == '1' && p[i] >= 0) {
			people ++;
			ren += to_string(order[i]);
			continue;
		}
		for (int j=i+1; j<vlen; j++){
			p[j]--;
		}
	}
	if (people >= m)
		ans.add(ren);
}
void run(vector<int> v, int cen){
	if (cen == n){
		onExam(v);
		return;
	}
	for (int i=1; i<=n; i++){
		if (any_of(v.begin(), v.end(), [&](int x){return x==i;})){
			continue;
		}
		vector<int> vc = v;
		vc.push_back(i);
		run(vc, cen+1);
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	cin >> exam;
	for (int i=1; i<=n; i++){
		scanf("%d", &c[i]);
	}
	
	for (int i=1; i<=n; i++){
		vector<int> v;
		v.push_back(i);
		run(v, 1);
	}
	cout << ans.ans % 998244353;
	return 0;
}

