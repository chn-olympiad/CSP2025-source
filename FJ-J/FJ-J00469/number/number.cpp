#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long number[10]={0};
	string str;
	cin >> str;
	for(long long i = 0;i < str.size();i++){
		if('0' <= str[i] && str[i] <= '9'){
			number[str[i]-'0']++;
		}
	}
	for(long long i = 9;i >= 0;i--){
		while(number[i]>0){
			cout << i;
			number[i]--;
		}
	}
	return 0;
}
