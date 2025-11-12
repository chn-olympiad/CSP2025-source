#include<bits/stdc++.h>
using namespace std;
int a[1000010],cnt;
char c[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",c);
	for(int i=0;i<strlen(c);i++)
		if(c[i]>='0'&&c[i]<='9')
			a[++cnt]=c[i]-'0';
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--)
		printf("%d",a[i]);
	return 0;
}