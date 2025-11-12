#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000005],c,r,myd,mydi,cnt,p[2005],t;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=m;j++)
			{
				cnt++;	
				scanf("%lld",&a[cnt]);
			}
	for(int i=n,j=1;i>=1;i--,j++)
	p[i]=j;
	myd=a[1];
	sort(a+1,a+1+cnt,cmp);
	for(long long i=1;i<=cnt;i++)
	{
		if(a[i]==myd)
		{mydi=i;break;}
	}
	//cout<<mydi<<endl;
	if(mydi<=n)
		printf("1 %lld",mydi);
	else
	{	
		c=mydi/m+1;
		if(mydi%m==0)t=1;
		else t=mydi%m;
		if(c%2==0)r=p[t];
		else r=t;
		printf("%lld %lld",c,r);
	}
	return 0;
} 
/*
2 2
99 100 97 98
*/
/*
2 2
98 99 100 97
*/
/*
3 3
94 95 96 97 98 99 100 93 92
*/
