#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a[1000005];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&s);
	int lens=strlen(s),lena=0;
	for(int i=0;i<lens;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[lena+1]=s[i]-'0';
			lena++;
		}
	}
	sort(a+1,a+lena+1,cmp);
	for(int i=1;i<=lena;i++){
		printf("%d",a[i]);
	}
	return 0;
}