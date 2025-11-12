#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char s[N];
int a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,0,sizeof(a));
	scanf("%s",s+1);
	int len=strlen(s+1),n=0;
	for(int i=1;i<=len;i++)if(isdigit(s[i]))a[++n]=s[i]-'0';
	sort(a+1,a+n+1,[](int x,int y){return x>y;});
	for(int i=1;i<=n;i++)printf("%d",a[i]);
	return 0;
}
