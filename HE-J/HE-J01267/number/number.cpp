#include <bits/stdc++.h>
using namespace std;
string str[1000000],s,st[1000000];
int cnt=1;
int main(){
  	freopen("number.in","r",stdin);
  	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i <= s.size();i++){
		st[i] = s[i];
		if(st[i] >= "0" && st[i] <= "9"){
			str[cnt] = st[i];
			cnt++;
		}
	}
	sort(str+1,str+1+cnt);
	for(int i = cnt;i > 0;i--){
		cout << str[i];
	}
	return 0;
} 
