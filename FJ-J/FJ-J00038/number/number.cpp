#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int cnt = 0,a[1010] = {};
	for(int i = 0;i<= 10000001;i++){
		if(s[i]-'0' >= 0 && s[i] - '0'<= 9){
			a[cnt] = s[i] - '0';
			cnt++;
		}
		if(s[i] - '0' == -48) break;
	}
	sort(a,a+cnt);
	for(int i = cnt-1;i >= 0;i--){
		cout << a[i];
	}
	return 0;
}
