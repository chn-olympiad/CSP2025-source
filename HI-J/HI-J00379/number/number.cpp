#include<bits/stdc++.h>
using namespace std;

int n,a[1010101],tot;
char s[1010101];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s+1;
	n=strlen(s+1);
	for(int i=1;i<=n;i++)if(s[i]-'0'>=0&&s[i]-'0'<=9)a[++tot]=s[i]-'0';
	sort(a+1,a+tot+1);
	for(int i=tot;i>=1;i--)printf("%d",a[i]);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
