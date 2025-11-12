#include<stdio.h>
#include<string.h>
char a[1000005]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//printf("1");
	scanf("%s",&a);
	int len=strlen(a);
	long long b[15]={0};
	for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=b[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}