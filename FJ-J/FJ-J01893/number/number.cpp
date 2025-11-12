#include<bits/stdc++.h>
using namespace std;
int b[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c;
	while(1){
		c=getchar();
		if(c=='\n'){
			break;
		}
		if(c>='0'&&c<='9'){
			b[c-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=b[i];j++){
			printf("%d",i);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
