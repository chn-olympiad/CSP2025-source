#include<bits/stdc++.h>
using namespace std;
int num[15];
char c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(num,0,sizeof(num));
	while(cin>>c){
		if(c>='0'&&c<='9')num[c-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++){
			printf("%d",i);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
