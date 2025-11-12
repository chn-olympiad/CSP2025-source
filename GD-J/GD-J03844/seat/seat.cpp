#include<bits/stdc++.h>
using namespace std;
int n,m,a_1,b[100],i_1,j_1,l;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	l=n*m;
	for(int i=1;i<=l;i++)
	{
		scanf("%d",&b[i]);
	}
	a_1=b[1];
	sort(b+1,b+l+1,cmp);
	for(int i=1;i<=l;i++)
	{
		if(b[i]==a_1)
		{
			i_1=i;
			break;
		}
	}	
	if(i_1<=n)
	{
		printf("1 %d",i_1);
	}
	else
	{
		j_1=ceil(1.0*i_1/n);
		i_1%=n;
		if(j_1%2!=0)
		{
			printf("%d %d",j_1,i_1);
		}
		else
		{
			printf("%d %d",j_1,n-i_1+1);
		}
	}
	return 0;
}

