#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int sum[N];
int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	string s;
	cin >> s;
	for(int i = 0 ; i < s.size() ; i ++){
		if(s[i] >= '0' && s[i] <= '9'){
			int num = s[i] - '0';
			sum[num] ++;
		}
	}
	for(int i = 9 ; i >= 0 ; i --){
		if(sum[i] != 0){
			for(int j = 1 ; j <= sum[i] ; j ++){
				cout << i;
			}
		}
	}
	return 0;
} 
