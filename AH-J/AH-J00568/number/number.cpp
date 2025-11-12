#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	int j=0,a[1000003];
	char s[1000003];
	scanf("%s",s);
	for(int i=0;s[i]!=0;i++){
		if((s[i]>='0')&&(s[i]<='9'))a[j++]=s[i]-48;
	}j--;sort(a,&a[j+1]);
	for(;j>=0;j--)printf("%d",a[j]);
	return 0;
}
