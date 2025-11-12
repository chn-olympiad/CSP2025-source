#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[1000005];
ll f[15],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&s);
	n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]>=48&&s[i]<=57)f[s[i]-48]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=f[i];j++){
			printf("%d",i);
		}
	}
	return 0;//zrt1
} 
