#include<bits/stdc++.h>
using namespace std;
int len,k,a[1000005];
char s[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1),len=strlen(s+1);
	for(int i=1;i<=len;i++) if('0'<=s[i]&&s[i]<='9') a[++k]=s[i]-'0';
	sort(a+1,a+1+k);
	for(int i=k;i>=1;i--) printf("%d",a[i]);
	return 0;
}
