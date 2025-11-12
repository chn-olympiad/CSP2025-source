#include<bits/stdc++.h>
using namespace std;
int a[1000006],n;
char s[1000006];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	for(int i=1;s[i];i++)
		if(s[i]<='9'&&s[i]>='0')
			a[++n]=s[i]-'0';
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++)
		putchar(a[i]+'0');
}