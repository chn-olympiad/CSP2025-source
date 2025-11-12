#include<stdio.h>
#include<string.h>
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n=0,m,c;
	char s,nc[1000];
	scanf("%s %d %s",nc,&m,s);
	for(int i=0;i<strlen(nc);i++){
		n*=10;
		n+=nc[i]-'0';
	}
	for(int i=0;i<strlen(nc);i++){
		char c=nc[strlen(nc)-i-1];
		nc[strlen(nc)-i-1]=nc[i];
		nc[i]=c;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c);
	}
	for(int i=n-1;i>=1;i--){
		char s2[1000];
		strcpy(s2,nc);
		int len=strlen(nc);
		for(int f=1;f<=i;i++){
			int flag=0;
			for(int j=0,k=len-1;k>=0;j++,k--){
				nc[j]=(flag+s2[k]-'0'+nc[j]-'0')%10;
				flag=(flag+s2[k]-'0'+nc[j]-'0')/10;
			}
		}	
	}	
	printf("%s",nc);
	return 0;
}
