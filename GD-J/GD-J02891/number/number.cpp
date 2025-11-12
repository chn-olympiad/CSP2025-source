#include<cstdio>
#include<cstring>
const int N=1e6+5;
char a[N];
int n[9];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a);
	int lena=strlen(a);
	for(int i=0;i<lena;i++){
		if(a[i]=='9'){
			printf("9");
			continue;
		}
		if(a[i]>=48&&a[i]<=57){
			n[a[i]-48]++;
		}
	}
	for(int i=8;i>=0;i--){
		while(n[i]>0){
			printf("%d",i);
			n[i]--;
		}
	}
	return 0;
}
 
