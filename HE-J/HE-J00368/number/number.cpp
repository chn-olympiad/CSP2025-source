#include<bits/stdc++.h>
using namespace std;
char s[110000];
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int len = strlen(s+1);
	int sum=0;
	for(int i = 1;i <= len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			sum++;
		}
	}
//	if(sum==len){
//		printf("%s",s+1);
//		return 0;
//	}
	for(int i = 1;i <= len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[s[i]-'0']++;
		}
	}
	for(int i = 9;i >= 0;i--){
		while(a[i]>0){
			printf("%d",i);
			a[i]--;
		}
	}
	return 0;
}
