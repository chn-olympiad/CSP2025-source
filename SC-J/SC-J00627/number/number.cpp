#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int m = 0;
	string n;
	cin >> n;
	for (int i = 1;i <= n.size();i++){
		if (n[i - 1] <= '9' && n[i - 1] >= '0'){
			m++;
			a[m] = n[i - 1] - '0';
		}
	}
	sort (a + 1, a + 1 + m);
	for (int i = m;i > 0;i--){
		cout << a[i];
	}
	return 0;
}