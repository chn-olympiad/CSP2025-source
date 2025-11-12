#include<bits/stdc++.h>
using namespace std;
char c;
int num[11] = {0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c){
		int c1=c - '0';
		if(c1>=0 && c1 <=9){
			num[c1] += 1;
		}
	}
	for(int i=9;i>=1;i--){
		if(num[i] != 0){
			for(int j=1;j<=num[i];j++){
				printf("%d",i);
			}
		}
	}
	return 0;
} 
