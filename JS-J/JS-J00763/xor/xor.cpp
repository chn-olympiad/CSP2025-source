#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a;
	bool b[22];
}m[5000];
int read()
{
	bool flag=0;
	int x=0;
	char c;
	c=getchar();
	while(!('0'<=c&&c<='9')) 
	{
		if(c=='-') flag=1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	if(flag) return -x;
	else return x;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,i,j;
	cin>>n>>k;
	for(i=1;i<=n;i++) m[i].a=read();
	
	if(k==0)
	{
		cout<<n/2;
	}
	for(i=1;i<=n;i++)
	{
		int x=m[i].a;
		j=0;                                       ;
		while(x>0)
		{
			m[i].b[j]=x%2;
			x=x/2;
			j++;
		}
	}
}
