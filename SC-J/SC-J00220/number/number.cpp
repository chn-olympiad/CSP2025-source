#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,tot;
char s[N],s2[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(isdigit(s[i]))
			s2[++tot]=s[i];
	sort(s2+1,s2+n+1,greater<>());
	printf("%s",s2+1);
	return 0;
}