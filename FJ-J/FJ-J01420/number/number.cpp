#include <bits/stdc++.h>
using namespace std;
int len;
int cnt[10];
char c[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",c);
	len=strlen(c);
	for(int i=0;i<len;i++){
		if(c[i]>='0'&&c[i]<='9'){
			cnt[c[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++){
			printf("%d",i);
		}
	}
	return 0;
} 
