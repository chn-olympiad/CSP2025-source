#include<bits/stdc++.h>
using namespace std;char a[1000009];int b,i,c[1000001],t;
main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	scanf("%s",a+1);b=strlen(a+1);for(i=1;i<=b;i++)if(a[i]>='0'&&a[i]<='9')c[++t]=a[i]-'0';
	sort(c+1,c+1+t);if(c[t]==0)return printf("0");for(i=t;i;i--)printf("%d",c[i]);
}
