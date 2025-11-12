#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	int a[10]={0,0,0,0,0,0,0,0,0,0};
	char c;
	while(c!='\n'){
		c=getchar();
		if(48<=c&&c<=57){
			a[c-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
