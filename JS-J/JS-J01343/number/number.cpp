#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,tot;
char a[N+5],ans[N+5];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a+1);n=strlen(a+1);
	for(int i=1;i<=n;i++) if(a[i]>='0'&&a[i]<='9') ans[++tot]=a[i];
	sort(ans+1,ans+1+tot,greater<char>());
	for(int i=1;i<=tot;i++) putchar(ans[i]);
	return 0;
}