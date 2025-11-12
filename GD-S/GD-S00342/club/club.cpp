#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
const int N = 1e5 + 10;
struct node {
	int a1, a2, a3;
} arr[N];
bool check(node a, node b) {
	if(a.a1 == b.a1 && a.a2 == b.a2 && a.a3 == b.a3) return 1;
	return 0;
}
bool cmpab(node a, node b) { // a -> b
	return (a.a2 - a.a1) > (b.a2 - b.a1);
}
bool cmpac(node a, node b) { // a -> c
	return (a.a3 - a.a1) > (b.a3 - b.a1);
}
bool cmpba(node a, node b) { // b -> a
	return (a.a1 - a.a2) > (b.a1 - b.a2);
}
bool cmpbc(node a, node b) { // b -> c
	return (a.a3 - a.a2) > (b.a3 - b.a2);
}
bool cmpca(node a, node b) { // c -> a
	return (a.a1 - a.a3) > (b.a1 - b.a3);
}
bool cmpcb(node a, node b) { // c -> b
	return (a.a2 - a.a3) > (b.a2 - b.a3);
}
void solve() {
	int n;
	cin >> n;
	rep(i, 1, n) {
		cin >> arr[i].a1 >> arr[i].a2 >> arr[i].a3;
	}
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	vector<node> v1, v2, v3;
	rep(i, 1, n) {
		int max_a = max(arr[i].a1, max(arr[i].a2, arr[i].a3));
		if(max_a == arr[i].a1) {
			v1.push_back(arr[i]);
			cnt1 += max_a;
		}
		else if(max_a == arr[i].a2) {
			v2.push_back(arr[i]);
			cnt2 += max_a;
		}
		else {
			v3.push_back(arr[i]);
			cnt3 += max_a;
		}
	}
	while(v1.size() > n / 2) {
		// ab
		sort(v1.begin(), v1.end(), cmpab);
		node tmp1 = v1[0];
		// ac
		sort(v1.begin(), v1.end(), cmpac);
		node tmp2 = v1[0];
		
		if((tmp1.a2 - tmp1.a1) > (tmp2.a3 - tmp2.a1)) { // ab good
			sort(v1.begin(), v1.end(), cmpab);
			v1.erase(v1.begin());
			v2.push_back(tmp1);
			cnt1 -= tmp1.a1;
			cnt2 += tmp1.a2;
		}
		else if((tmp1.a2 - tmp1.a1) < (tmp2.a3 - tmp2.a1)) {
			sort(v1.begin(), v1.end(), cmpac);
			v1.erase(v1.begin());
			v3.push_back(tmp2);
			cnt1 -= tmp2.a1;
			cnt3 += tmp2.a3;
		}
		else {
			if(v2.size() < v3.size()) { //ab
				v1.erase(v1.begin());
				v2.push_back(tmp1);
				cnt1 -= tmp1.a1;
				cnt2 += tmp1.a2;
			}
			else { // ac
				v1.erase(v1.begin());
				v3.push_back(tmp2);
				cnt1 -= tmp2.a1;
				cnt3 += tmp2.a3;
			}
		}
	}
	while(v2.size() > n / 2) {
		// ba
		sort(v2.begin(), v2.end(), cmpba);
		node tmp1 = v2[0];
		// bc
		sort(v2.begin(), v2.end(), cmpbc);
		node tmp2 = v2[0];
		
		if((tmp1.a1 - tmp1.a2) > (tmp2.a3 - tmp2.a2)) { // ba good
			sort(v2.begin(), v2.end(), cmpba);
			v2.erase(v2.begin());
			v1.push_back(tmp1);
			cnt2 -= tmp1.a2;
			cnt1 += tmp1.a1;
		}
		else if((tmp1.a1 - tmp1.a2) < (tmp2.a3 - tmp2.a2)) { // bc good
			sort(v2.begin(), v2.end(), cmpbc);
			v2.erase(v2.begin());
			v3.push_back(tmp2);
			cnt2 -= tmp2.a2;
			cnt3 += tmp2.a3;
		}
		else {
			if(v1.size() < v3.size()) {
				v2.erase(v2.begin());
				v1.push_back(tmp1);
				cnt2 -= tmp1.a2;
				cnt1 += tmp1.a1;
			}
			else {
				v2.erase(v2.begin());
				v3.push_back(tmp2);
				cnt2 -= tmp2.a2;
				cnt3 += tmp2.a3;
			}
		}
	}
	while(v3.size() > n / 2) {
		// ca
		sort(v3.begin(), v3.end(), cmpca);
		node tmp1 = v3[0];
		// cb
		sort(v3.begin(), v3.end(), cmpcb);
		node tmp2 = v3[0];
		
		if((tmp1.a1 - tmp1.a3) > (tmp2.a2 - tmp2.a3)) { // ca good
			sort(v3.begin(), v3.end(), cmpca);
			v3.erase(v3.begin());
			v1.push_back(tmp1);
			cnt3 -= tmp1.a3;
			cnt1 += tmp1.a1;
		}
		else if((tmp1.a1 - tmp1.a3) < (tmp2.a2 - tmp2.a3)) { // cb good
			sort(v3.begin(), v3.end(), cmpcb);
			v3.erase(v3.begin());
			v2.push_back(tmp2);
			cnt3 -= tmp2.a3;
			cnt2 += tmp2.a2;
		}
		else {
			if(v1.size() < v2.size()) {
				v3.erase(v3.begin());
				v1.push_back(tmp1);
				cnt3 -= tmp1.a3;
				cnt1 += tmp1.a1;
			}
			else {
				v3.erase(v3.begin());
				v2.push_back(tmp2);
				cnt3 -= tmp2.a3;
				cnt2 += tmp2.a2;
			}
		}
	}
	cout << cnt1 + cnt2 + cnt3 << endl;
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve(); 
	return 0;
}
