#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
long long a[10];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	long long  n = s.size();
	for(int i = 0; i < n; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			int x = s[i] - '0';
			a[x]++;
		}
	}
	for(int i = 9; i >= 0; i--){
		if(a[i] != 0){
			while(a[i]--){
				cout << i;
			}
		}
	}
	return 0;
}