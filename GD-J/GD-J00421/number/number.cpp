#include<bits/stdc++.h>
using namespace std;
string a;
vector<int> b;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> a;
	for(int i = 0; i < a.size(); i++){
		if(a[i] >= '0' && a[i] <= '9'){
			b.push_back(a[i] - '0');
		}
	}
	sort(b.begin(), b.end());
	for(int i = b.size() - 1; i >= 0; i--){
		cout << b[i];
	}
	return 0;
}
