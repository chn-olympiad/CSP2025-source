#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("number.in",'r',stdin);
	freopen("number.out",'w',stdout);
	string s;
	int a[15];
	long long sum;
	cin >> s;
	for(int i = 0;i <= 14;i++) a[i] = 0;
	for(int i = 0;i <= s.length();i++){
		if(s[i] <= 57 and s[i] >= 48){
			a[s[i] - 48]++;
		}
	}
	for(int i = 9;i >= 0;i--){
		for(int j = 1;j <= a[i];j++){
			sum *= 10;
			sum += i;
		}
	}cout << sum;
	return 0;
} 
