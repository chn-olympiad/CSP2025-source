#include <bits/stdc++.h>
using namespace std;
int nums[1000005], tong[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i ++){
		if (s[i] >= '0' && s[i] <= '9'){
			nums[i] = s[i] - '0';
		}
	}
	for (int i = 0; i < len; i ++){
		if (s[i] >= '0' && s[i] <= '9'){
			tong[nums[i]] += 1;
		}
	} 
	for (int i =1000005; i >= 0; i --){
		if (tong[i] != 0){
			for (int j = 1; j <= tong[i]; j ++){
				cout << i;
			}
		} 
	} 
	return 0;
}
