#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int k,n;
int ga,gb,gc,sum;
int A[N],B[N],C[N];
void work()
{
	ga=0,gb=0,gc=0,sum=0;
	memset(A,0,sizeof(A));
	memset(B,0,sizeof(B));
	memset(C,0,sizeof(C));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int Max,Nex;
		if(a>=b&&a>=c)
		{
			Max=a;
			Nex=max(b,c);
			A[++ga]=Max-Nex;
		}
		else if(b>=c&&b>=a)
		{
			Max=b;
			Nex=max(a,c);
			B[++gb]=Max-Nex;
		}
		else
		{
			Max=c;
			Nex=max(a,b);
			C[++gc]=Max-Nex;
		}
		sum+=Max;
	}
	if(ga>n/2)
	{
		sort(A+1,A+1+ga);
		for(int i=1;i<=ga-(n/2);i++)
			sum-=A[i];
	}
	if(gb>n/2)
	{
		sort(B+1,B+1+gb);
		for(int i=1;i<=gb-(n/2);i++)
		{
			sum-=B[i];
		}
			
	}
	if(gc>n/2)
	{
		sort(C+1,C+1+gc);
		for(int i=1;i<=gc-(n/2);i++)
			sum-=C[i];
	}
	printf("%d\n",sum);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&k);
	while(k--)
	{
		work();
	}
	return 0;
}