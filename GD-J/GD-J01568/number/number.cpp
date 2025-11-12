#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

char s[1000010];
long long n[15];

int main(){
	freopen("number.in", "r", "stdin");
	freopen("number.out", "w", "stdout");
	cin >> s;
	for(int i=0; i<=strlen(s); i++){
		if(s[i]>='0'&&s[i]<='9'){
			n[int(s[i])-48]++;
		}
	}
	for(int i=9; i>=0; i--){
		while(n[i]>0){
			cout << i;
			n[i]--;
		}
	}
	return 0;
}
