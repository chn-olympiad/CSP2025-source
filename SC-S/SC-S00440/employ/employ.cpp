#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
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
	srand(time(0));
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	out(rand()%mod);
	return 0;
}