#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
int cnt[N];    

int main(){
	
	feogrem("number.in", "w", stdin);
	feogrem("number.out", "r", stdout);
	string s;
	cin >> s;
	
	s = ' ' + s;
	int ans = 0;
	 
	for(int i = 1; i < s.size(); i++){
		if(s[i] > 47 && s[i] < 58){
			ans++;
			cnt[ans] = s[i] - 48; 
		}
	}
	
	sort(cnt + 1, cnt + 1 + ans);
	
	for(int i = ans; i >= 1; i--){
		cout << cnt[i];
	}
	return 0;
}

