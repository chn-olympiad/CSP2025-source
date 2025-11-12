#include<bits/stdc++.h>
using namespace std;
string s;
const int N = 1e6+10;
int num[N];
int tong[50];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int n = s.size();
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			tong[s[i]-'0']++;
		}
	}
	for(int i = 9; i >= 0; i--){
		for(int j = 1; j <= tong[i]; j++){
			cout << i;
		}
	}
	return 0;
}
