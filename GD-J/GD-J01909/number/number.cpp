#include <bits/stdc++.h>
using namespace std;
string s;
int a[10],y,f;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(isdigit(s[i])){
			a[s[i]-'0']++;
	    }
	}for(int i = 9;i >= 0;i--){
		if(i == 0 && !f){
			printf("0");
			return 0;
		}for(int j = 1;j <= a[i];j++){
			printf("%d",i);
			f = 1;
		}
	}return 0;
}
