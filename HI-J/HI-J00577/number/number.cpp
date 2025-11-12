#include<bits/stdc++.h>
using namespace std;
int a[1000010];
char s[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int l=strlen(s+1);
	int sum=0;
	for(int i=1;i<=l;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			sum++;
			a[sum]=s[i]-'0';
		}
	}
	sort(a+1,a+sum+1);
	for(int i=sum;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
}

