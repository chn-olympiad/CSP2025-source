#include<bits/stdc++.h>
#include<string>
using namespace std;

string str="";
int num[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> str;
	for (int i = 0;i <= str.length();i++){
		int res = int(str[i])-48;
		if (res <= 9 && res >= 0){
			num[res]++;
		}
	}
	for (int j = 9;j >= 0;j--){
		for (int i = 1;i <= num[j];i++){
			cout << j;
		}
	}
	return 0;
} 
