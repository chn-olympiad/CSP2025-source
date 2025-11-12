#include<bits/stdc++.h>
using namespace std;
char c[1000005];
int t[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int Len=0;
	while(scanf("%c",&c[++Len])){ 
	    if(c[Len]>='0'&&c[Len]<='9'){
    	t[c[Len]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++){
			printf("%c",char(i+'0'));
		}
	}
	return 0;
} 
