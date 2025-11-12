#include<bits/stdc++.h>
#define LL long long
using namespace std;
string s;
int a[10];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> s;
	int n = s.size();
	s = " " + s;
	bool p = true;
	for(int i = 1;i <= n;i++){
		if(isdigit(s[i])){
			a[s[i] - '0']++;
			if(s[i] != 0){
				p = false;
			}
		}
	}
	if(p){
		cout << 0;
		return 0;
	}else{
		for(int i = 9;i >= 0;i--){
			if(a[i] != 0){
				while(a[i]--){
					cout << i;
				}
			}
		}
	}
	return 0;
}
