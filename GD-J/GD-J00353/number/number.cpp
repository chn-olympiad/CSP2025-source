#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	unordered_map<int, int> cnt;
	string s;
	cin >> s;
	for(int i=0;i<s.size();++i)
		if(s[i]>=48&&s[i]<=57)
			cnt[s[i]-48]++;
	bool b = false;
	for(int i=9;i>=1;--i){
		for(int j=1;j<=cnt[i];++j){
			cout << i;
			b = true;
		}
	}
	if(!b) cout << 0;
	else for(int i=1;i<=cnt[0];++i)
		cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
