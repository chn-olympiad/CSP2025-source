#include<bits/stdc++.h>
using namespace std;
int A[5005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int N,P,Q,Ans;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&A[i]);
	sort(A+1,A+N+1,cmp);
	if(N==3)
	{
		if(A[3]+A[2]>A[1])
			printf("1");
		else 
			printf("0");
		return 0;
	}
	else if(A[1]==1)
	{
		for(int i=3;i<=N;i++)
		{
			P=N;
			Q=1;
			for(int j=2;j<=i;j++)
			{
				P=(P*(N-j+1))%998244353;
				Q=(Q*j)%998244353;
			}
			Ans+=P/Q;
		}
		printf("%d",Ans);
		return 0;
	}
	return 0;
}
