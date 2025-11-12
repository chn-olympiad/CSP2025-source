#include<bits/stdc++.h>
using namespace std;

const int Max = 5e5 + 7;
long long n, k, x, ans = 0;
long long a[Max];
set<long long> p;

void f(long long num){
	if (p.empty()){
		p.insert(num);
		return;
	}
	set<long long> px;
	for(auto i : p){
		x = i xor num;
//		cout << "now i'm check " << i << " xor " << num << " = " << x << "\n";
		if (x == k){
			ans++;
//			cout << "hard work! ans++\n";
			p.clear();
			return;
		}
		px.insert(x);
	}
	p = px;
	p.insert(num);
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++){
		if (a[i] == k){
			ans++;
//			cout << "luck work! ans++\n";
			p.clear();
			continue;
		}
		f(a[i]);
	}
	cout << ans << "\n";
	return 0;
}
