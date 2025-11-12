#include <iostream>
#include <string>
using namespace std;
string s;
int cnt[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	
	for (int i = 0;i<s.size();i++){
		char c = s[i];
		if (c >= '0' && c <= '9') cnt[c - '0']++;
	}
	for (int i = 9;i>=0;i--){
		while(cnt[i]>=1){
			cout << i;
			cnt[i]--;
		}
	}
	return 0;
}