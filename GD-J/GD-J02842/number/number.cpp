#include<bits/stdc++.h>
using namespace std;
char s[1100000];
int a[1100000];
int num;

int main(){
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout);	
	scanf("%s",s+1);
	for(int i=1;i<=strlen(s+1);i++){
		if(s[i]>='0'&&s[i]<='9') {
			num++;
			a[num]=s[i]-'0';
		}
	}
	sort(a+1,a+num+1);
	for(int i=num;i>=1;i--){
		if(i==num&&a[i]==0){
			printf("0");
			return 0;
		}
		else printf("%d",a[i]);
	}
	return 0;

}
