#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
string str;
int cnt[10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> str;
	for(int i = 0;i < str.size();i++){
		if(str[i] >= '0' && str[i] <= '9'){
			int num = str[i] - '0';
			cnt[num]++;
		}
	}
	for(int i = 9;i >= 0;i--){
		while(cnt[i] > 0){
			cout << i;
			cnt[i]--;
		}
	}
	return 0;
}