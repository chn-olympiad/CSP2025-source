#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int a[15]={0},x;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int l=strlen(s);
	for(int i=0;i<l;i++){
		if(s[i]>='0' && s[i]<='9'){
			x=s[i]-'0';
			a[x]++;
		}
	}
	for(int i=15;i>=0;i--){
		while(a[i]>0){
			printf("%d",i);
			a[i]--;
		}
	}
	return 0;
}
