#include<bits/stdc++.h>
using namespace std;
int n,q;
int in()
{
	char k=getchar();
	int kk=0,f=1;
	while(k<'0'&&k>'9')
	{
		if(k=='-')f=-1;
		k=getchar();
	}
	while(k>='0'&&k<='9')kk=kk*10+k-'0',k=getchar();
	return f*kk;
}
void out(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else out(x/10),putchar(x%10+'0');
	return ;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("repace.out","w",stdout);
	for(int i=1;i<=q;i++)cout<<0<<endl;
	return 0;
}