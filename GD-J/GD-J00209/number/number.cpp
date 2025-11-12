#include<iostream>
#include<algorithm>
using namespace std;

char c[1000005];
int cnt = 0;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if ('0' <= s[i] && s[i] <= '9'){
			c[++cnt] = s[i];
		}
	}
	sort(c+1, c+cnt+1, greater<int>());
	for (int i = 1; i <= cnt; i++){
		cout << c[i];
	}
	return 0;
} 

/*

#include<iostream>
#include<algorithm>
using namespace std;

string ans;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if ('0' <= s[i] && s[i] <= '9'){
			ans += s[i];
		}
	}
	sort(ans.begin(), ans.end(), greater<int>());
	cout << ans;
	return 0;
} 

*/
