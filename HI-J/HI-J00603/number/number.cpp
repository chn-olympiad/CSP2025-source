#include<bits/stdc++.h>
using namespace std;
char a[1101101];
int b[1101101];
int cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a+1);
	int len=strlen(a+1);
	for(int i=1;i<=len;i++){
		if(a[i]>='0' && a[i]<='9'){
			b[++cnt]=a[i]-'0';
		}
	}
	if(!cnt){
		printf("0");
		fclose(stdin);
	    fclose(stdout);
	    return 0;
	}
	sort(b+1,b+1+cnt);
	for(int i=cnt;i;i--){
		printf("%d",b[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
