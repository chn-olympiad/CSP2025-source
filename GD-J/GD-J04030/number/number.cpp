#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,a[N];
char s[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;i++)
		if('0'<=s[i]&&s[i]<='9')
			a[++n]=s[i]-'0'; 
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)
		printf("%d",a[i]);
	return 0;
}
