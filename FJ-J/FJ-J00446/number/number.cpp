#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
string s;
int cnt, tot;
int a[N];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for(int i = 0 ;i < len; i ++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[++tot] = s[i] - '0';
			cnt++;
		}
	}
//	cout << cnt <<"\n";
	sort(a, a + cnt);
	for(int i = cnt - 1; i >= 0; i--){
		cout << a[i];
	}
	cout << "\n";
	return 0;
}
