#include <bits/stdc++.h>
using namespace std;

int n,l;
char s[1000011],ans[1000011]; 

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s + 1);
	n = strlen(s + 1);
	for(int i=1;i<=n;i++) {
		if (s[i] >= '0' && s[i] <= '9')
			ans[++l] = s[i];
	}
	sort(ans + 1,ans + l + 1);
	for(int i=l;i>=1;i--)
		printf("%c",ans[i]);
	return 0;
} 
