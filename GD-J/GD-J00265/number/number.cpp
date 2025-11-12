#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[10] = {};
	int cnt = 0,ans = 0;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '1' && s[i] <= '9'){
			a[s[i] - '0']++;;
		}
	}
	for(int i = 9; i >= 1; i--){
		while(a[i]){
			cout << i;
			a[i]--;
		}
	}
	return 0;
}
