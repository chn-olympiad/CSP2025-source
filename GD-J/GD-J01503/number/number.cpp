#include <bits/stdc++.h>
const int N=1e6+5;
char s[N];
int n,cnt[15];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(s[i]>='0'&&s[i]<='9')
			cnt[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(;cnt[i]>0;cnt[i]--)
			putchar(i+48);
	return 0;
}
