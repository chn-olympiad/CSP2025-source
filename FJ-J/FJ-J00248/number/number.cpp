#include <bits/stdc++.h>
using namespace std;
char a[1000001];
int s[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&a);
	for(int i=0;i<strlen(a);i++){
		if(a[i]>='0'&&a[i]<='9'){
			s[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<s[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}
