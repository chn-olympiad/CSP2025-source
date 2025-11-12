#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int main(){
	int b;
	cin >> b;
	char a;
	cin >> a;
	int number[10];
	for(int i = 0;i < 10;i++){
		number[i] = 0;
	}
	for(int i = 0;i < b;i++){
		if((a[i] >= '0')&&(a[i]<='9')){
			int s = a[i] - 48;
			number[s]++;
		}
	}
	for(int i = 9;i >=0;i--){
		for(int l = 0;l<number[i];l++){
			cout<<i;
		}
	}
}
