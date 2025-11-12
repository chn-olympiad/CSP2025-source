#include<bits/stdc++.h>
# define Maxn 1000005
using namespace std;
int n,ans[Maxn],top;
char s[Maxn];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++) {
		if(s[i]>='a'&&s[i]<='z') continue;
		ans[++top]=s[i]-'0'; 
	}sort(ans+1,ans+top+1);
	for(int i=top;i>=1;i--) printf("%d",ans[i]);
	return 0;
}
