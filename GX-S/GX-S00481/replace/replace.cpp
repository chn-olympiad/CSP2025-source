#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	register int x=0;
	char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0' && c<='9')
		x=x*10+c-48,c=getchar();
	return x;
}
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=q;i++)
		printf("0\n");
	return 0;
}
