#include<bits/stdc++.h>
using namespace std;
char c[5000005];
bool cmp(int x , int y){
	return x > y;
}
int a[15]; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> c;
	int  cnt = 0 , num;
	for(int i = 0 ; i <= 10 ; i++) a[i] = 0;
	for(int i = 0 ; i < strlen(c) ; i++){
		if(c[i] >= '0' && c[i] <= '9'){
			num = c[i] - '0';
			a[num]++;
		}
	}
	for(int i = 9 ; i >= 0 ; i--){
		for(int j = 1 ; j <= a[i] ; j++) cout << i;
	}
	return 0;
}
