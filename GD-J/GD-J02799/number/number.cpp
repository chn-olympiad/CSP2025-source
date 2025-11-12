#include<bits/stdc++.h>
using namespace std;
int a[10],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000007];
	cin >> s;
	for(int i = 0;i<strlen(s);i++){
		if(isdigit(s[i])){
			a[s[i]-'0']++;
		}
	}for(int i = 9;i>=0;i--){
		while(a[i]){
			cout << i;
			a[i]--;
		}
	}
	
	return 0;
} 
