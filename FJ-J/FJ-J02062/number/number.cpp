#include<bits/stdc++.h>
using namespace std;

string s;
long long a[15];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	scanf("%s", &s);
	for(int i=0; i<s.size(); i++){
		if(s[i]>='0' && s[i]<='9'){
			a[s[i]-'0'] ++;
		}
	}
	
	for(int i=9; i>=0; i--){
		while(a[i] != 0){
			printf("%d", i);
			a[i]--;
		}
	}
	printf("\n");
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
