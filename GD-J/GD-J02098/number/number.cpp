#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];char s[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);int l=strlen(s);int r=0;
	for(int i=0;i<l;i++)
		if(s[i]<='9'&&s[i]>='0')a[++r]=s[i]-'0';
	sort(a+1,a+r+1);
	for(int i=r;i>=1;i--)printf("%d",a[i]);
	return 0;
}
