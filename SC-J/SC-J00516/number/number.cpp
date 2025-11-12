#include <bits/stdc++.h>
using namespace std;
int cnt[10]{0,0,0,0,0,0,0,0,0,0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n = s.size();
	for(int i = 0; i < n; i ++){
		if(int(s[i] - '0') < 10){
			cnt[int(s[i] - '0')]++;
			
		}
	}
	for(int i = 9; i >= 0; i --){
		for(int j = 0; j < cnt[i]; j++){
			cout<<i;
		}
	}
	return 0;
}