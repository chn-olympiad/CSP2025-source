#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int a[1000010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&s);
	for(int i=0;i<strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[0]++;
			a[a[0]]=s[i]-'0';
		}
	}
	sort(a+1,a+1+a[0],cmp);
	for(int i=1;i<=a[0];i++){
		printf("%d",a[i]);
	}
	return 0;
}
