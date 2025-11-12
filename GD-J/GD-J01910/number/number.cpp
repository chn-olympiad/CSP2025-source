#include<cstdio>
using namespace std;
char s[1000003];
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf(" %s",s);
	for(int i=0;s[i]!=EOF;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]--){
			printf("%d",i);
		}
	}
	return 0;
}
