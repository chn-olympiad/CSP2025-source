#include<bits/stdc++.h>
#define int long long

using namespace std;

int t[20];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin >> s;
	for (char i:s){
		if ('0'<=i && i<='9'){
			t[i-'0']++;
		}
	}
	for (int i=9;i>=0;i--){
		while(t[i]){
			cout << i;
			t[i]--;
		}
	}
	
	return 0;
}

