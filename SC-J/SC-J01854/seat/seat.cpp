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
int n,m,k=1,sw;
int s;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	read(n);
	read(m);
	read(sw);
	//write(m*n);
	for(int i=2;i<=m*n;i++)
	{
		read(s);
		//write(s);
		if(sw<s)
		{
			k++;
			
		}
	}
	int w=(k+n-1)/n;
	//write(k);
	int l;
	if(w%2==1)
	{
		l=k%n;
		if(l==0){
			l=n;
		}
	}
	else{
		l=n-k%n+1;
		if(l==0){
			l=n;
		}
	}
	write(w);
	putchar(' ');
	write(l);
}