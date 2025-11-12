#include<bits/stdc++.h>
using namespace std;
int a[10];
char c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c){
		if(0<=c-'0'&&c-'0'<=9){
			a[c-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}
