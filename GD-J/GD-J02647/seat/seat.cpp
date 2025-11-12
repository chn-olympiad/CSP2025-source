#include<std::bits/c++.h>
using namespace std::
int N,M,K=1,a[125];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&N,&M);//NÐÐMÁÐ
	for(int i=1;i<=N*M;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]>a[1])
			K++;
	}
	int Y=K/M+1;
	if (K%M==0)
		Y--;
	int X;
	if (Y%2==1)
	{
		X=K%M;
		if (X==0)
			X=M;
	}
	else
	{
		X=M-K%M+1;
		if (X==M+1)
			X=1;
	}
	printf("%d%d",Y,X);
	return 0;
}
