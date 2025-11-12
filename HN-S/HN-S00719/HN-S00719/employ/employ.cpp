#include <bits/stdc++.h>
#include <string.h>
#include <stdio.h>
using namespace std;

int n;
int employ(int cnt)
{
	int m,c[n+3]
	string S[505]
	cnt=0;
	int i=1,j=1;
	fscanf("%d%d",&n,&m);
	for(;i<=n;i++)
	{	
		fscanf("%s",S[505]);	
	}
	for(;i<=n;i++)
	{
		fscanf("%d",c[n+3]);
	}
	for(;i<=n;i++)
	{
		int S[i]
		if(S[i]!=0)
		{
			cnt+=0;
		}
		else
		{
			cnt+=1;
		}
	}	
	return cnt;
}
int P(int sum)
{
	sum=0;
	int a,i=1,j=1,Cnt=1,Sum=1,sum1=0,X=1,cnt1=0,sum2=0;
	a=employ();
	for(;i<=n;i++)
	{
		Sum=Sum*i;
	}
	for(;j<=cnt;j++)
	{
		Cnt=Cnt*j;
	}
	for(;X<=n-cnt;X++)
	{
		sum1=sum1*X;
	}
	cnt1=sum1*Cnt;
	sum2=Sum/cnt1;
	return sum2;
}
int main()
{
	fropen("employ.in","r",stdin);
	fropen("employ.out","w",stdout);
	
	int Pshuliang;
	Pshuliang=P();
	fprintf("%d\n",&Pshuliang);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
