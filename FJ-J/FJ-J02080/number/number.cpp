#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int ans[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int len=strlen(s),tot=0;
	for(int i=0;i<len;i++)
		if('0'<=s[i] && s[i]<='9')
			ans[++tot]=s[i]-'0';
	sort(ans+1,ans+tot+1,greater<int>());
	for(int i=1;i<=tot;i++)
		printf("%d",ans[i]);
	puts("");
	return 0;
} 
