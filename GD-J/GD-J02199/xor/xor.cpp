#include<bits/stdc++.h>
using namespace std;
int n,t,f[500010],res,k=1;
void read(int &x)
{
	x=0;
	char ch=getchar();
	while(!isdigit(ch))
		ch=getchar();
	while(isdigit(ch))
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
}
void write(int x)
{
	if(x>9)
		write(x/10);
	putchar((x%10)^48);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	read(n),read(t);
	for(int i=1;i<=n;i++)
	{
		int x;
		read(x);
		f[i]=f[i-1]^x;
	}
	for(int i=1;i<=n;i++)
	{
		bool flag=false;
		int j=k;
		for(;j<=i;j++)
			if((f[i] xor f[j-1])==t)
			{
//				printf("%d %d\n",j,i);
				flag=true;
				break;
			}
		if(flag)
		{
			res++;
			k=i+1;
		}
	}
	write(res);
	return 0;
}
