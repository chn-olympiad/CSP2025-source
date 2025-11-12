#include<bits/stdc++.h>
using namespace std;
int n,k,a[500003],m=0,num=0;
int b[5][53],b1=0,b2=0,b3=0,re=0,d=1;
int f(int x,int y)
{
	memset(b,0,sizeof(b));
	b1=0,b2=0,b3=0,re=0,d=1;
	if(x==0) b[1][++b1]=0;
	else
	{
		for(;x>0;x/=2)
			b[1][++b1]=x%2;
	}
	if(y==0) b[2][++b2]=0;
	else
	{
		for(;y>0;y/=2)
			b[2][++b2]=y%2;
	}
	b3=max(b1,b2);
	for(int i=1;i<=b3;i++)
		if(b[1][i]!=b[2][i]) b[3][i]=1;
	for(int i=1;i<=b3;i++)
	{
		re+=d*b[3][i];
		d*=2;
	}
	return re;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	m=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int m2=0;
		num=0;
		for(int j=i;j<=n;j++)
		{
			num=f(a[j],num);
			if(num==k) num=0,m2++;
		}
		m=max(m,m2);
	}
	printf("%d",m);
	return 0;
}
