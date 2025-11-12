#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char op[N];
int a[N],tot=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",op+1);
	int len=strlen(op+1);
	for(int i=1;i<=len;i++)
	if(op[i]>='0' && op[i]<='9') a[++tot]=op[i]-'0';
	sort(a+1,a+1+tot);
	for(int i=tot;i>=1;i--) printf("%d",a[i]);
	return 0;
}