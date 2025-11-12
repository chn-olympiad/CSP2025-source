#include<bits/stdc++.h>
using namespace std;
char ch;
int tot[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>ch){
		if('0'<=ch && ch<='9') tot[ch-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(tot[i]!=0){
			printf("%d",i);
			tot[i]--;
		} 
	}
	return 0;
} 
