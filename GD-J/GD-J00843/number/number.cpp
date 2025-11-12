#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 5;
string s;
int n, a[N];
int main(){
	cin >> s;
	int j = 0;
	for(int i = 0; i < s.size(); i++){
		if('0' <= s[i] && s[i] <= '9'){
			a[++j] = s[i]- '0';
		}
	}
	long long ans = 0;
	sort(a + 1, a + 1 + j);
	for(int i = j; i >= 1; i--){
		ans = ans * 10 + a[i];
	}
	cout << ans << endl;
	return 0;
} 
