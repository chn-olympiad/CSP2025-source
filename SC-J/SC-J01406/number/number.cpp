#include <bits/stdc++.h>
using namespace std;

char s[1000100];
long long  a[15];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(s[i]-'0'<=9&&s[i]-'0'>=0){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(long long j=1;j<=a[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}