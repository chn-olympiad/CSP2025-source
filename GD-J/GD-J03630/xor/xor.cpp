#include<bits/stdc++.h>
using namespace std;
int A[200005],Rp[2];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int N,K,Ans;
	scanf("%d%d",&N,&K);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&A[i]);
		Rp[A[i]]++;
	}
	if(Rp[0]==0)
	{
		N/=2;
		printf("%d",&N);
		return 0;
	}
	if(K==0)
		Ans=Rp[0]+Rp[1]/2;
	else
		Ans=Rp[1];
	printf("%d",Ans);
	return 0;
}
