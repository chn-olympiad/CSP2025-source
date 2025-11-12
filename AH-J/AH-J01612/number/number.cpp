#include<bits/stdc++.h>
using namespace std;
char c[2000005];
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=0,i,len;
	scanf("%s",c);
	len=strlen(c);
	for(i=0;i<=len-1;i++){
		if(c[i]<='9'&&c[i]>='0')
			a[++n]=c[i]-'0';
	}
	sort(a+1,a+n+1);
	for(i=n;i>=1;i--)
		printf("%d",a[i]);
	return 0;
}
