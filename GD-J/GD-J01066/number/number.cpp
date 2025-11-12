#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int n,cnt[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++) if(s[i]>=48&&s[i]<=57) cnt[s[i]-48]++;
	for(int i=9;~i;i--) while(cnt[i]--) putchar(i+48);
	return 0;
}
