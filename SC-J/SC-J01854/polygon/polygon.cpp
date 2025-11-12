#include<bits/stdc++.h>
using namespace std;
inline void read(int &a)
{
	int s=0,w=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')
		{
			w=-1;
		}
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	a=s*w;
} 

void write(int a)
{
	if(a<0)
	{
		a=-a;
	}
	if(a>9)
	{
		write(a/10);
	}
	putchar(a%10+'0');
}
const int maxn=998244535;
bool cmp(int a,int b)
{
	return a<b;
}

int w[5003];
int n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	read(n);
	if(n<=3)
	{
		int sum=0,maxnn=0;
		if(n==3)
		{
			for(int i=1;i<=3;i++)
			{
				read(w[i]);
				sum+=w[i];
				maxnn=max(maxnn,w[i]);
			}
			if(sum>maxnn*2)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
		else{
			cout<<'0';
		}
	}

	
	
}