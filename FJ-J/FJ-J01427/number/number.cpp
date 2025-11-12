#include<bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in","r",stdin);\
				freopen(x".out","w",stdout)
int a[10];
string s;
int main(){
	FILE("number");
	cin >> s;
	for(int i=0;i<s.length();i++){
		switch(s[i]){
			case '0':
				a[0]++;
				break;
			case '1':
				a[1]++;
				break;
			case '2':
				a[2]++;
				break;
			case '3':
				a[3]++;
				break;
			case '4':
				a[4]++;
				break;
			case '5':
				a[5]++;
				break;
			case '6':
				a[6]++;
				break;
			case '7':
				a[7]++;
				break;
			case '8':
				a[8]++;
				break;
			case '9':
				a[9]++;
				break;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout << i;
		}
	}
	return 0;
}

