#include <bits/stdc++.h>
using namespace std;
int cnt[55];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int len = s.size();
	for(int i = 0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	for(int i = 9;i>=0;i--){
		for(int j = 1;j<=cnt[i];j++){
			cout << i;
		}
	}
	return 0;
}
