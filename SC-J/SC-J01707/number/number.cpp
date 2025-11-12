#include<bits/stdc++.h>
using namespace std;
long long arr[10] = {};
int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	string str;
	cin >> str;
	for (long long i = 0;i < str.length();i ++){
		if ('0' <= str[i] && str[i] <= '9'){
			arr[str[i] - '0'] ++;
		}
	}
	for (long long i = 9;i >= 0;i --){
		for (long long j = 1;j <= arr[i];j ++){
			printf("%d" , i);
		}
	}
	return 0;
}