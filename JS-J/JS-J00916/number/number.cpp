#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
char s[N],t[N];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m=0;
	scanf("%s",s+1),n=strlen(s+1);
	for (int i=1;i<=n;++i)
		if (isdigit(s[i])) t[++m]=s[i];
	sort(t+1,t+m+1,greater<char>());
	puts(t+1);
	return 0;
}