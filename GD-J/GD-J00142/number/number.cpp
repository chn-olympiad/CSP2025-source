#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a[1000005],cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	for(int i=0;s[i]!='\0';i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=(int)(s[i]-'0');
		}
	}
	sort(a+1,a+cnt+1);
	if(a[cnt]==0) puts("0");
	else{
		for(int i=cnt;i>0;i--){
			printf("%d",a[i]);
		}
	}
	return 0;
}
