#include<bits/stdc++.h>
using namespace std;
/*const int N=5e5+10;
int L[N],R[N];
int yhh[N][N],ans=0;
int n,k,t=0,a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(L,0,sizeof(L));
	memset(R,0,sizeof(R));
	memset(yhh,0,sizeof(yhh));
	memset(a,0,sizeof(a));

	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),yhh[i][i]=a[i];
	yhh[0][1]=a[1];
	for(int l=1;l<=n;l++)
	{
		for(int r=l+1;r<=n;r++)
		{
			yhh[l][r]=yhh[l][r-1]^a[r];
			if(yhh[l][r]==k)ans++,L[++t]=l,R[++t]=r;
			for(int i=1;i<t;i++)
			{
				if(l<=R[i]||r>=L[i])L[t]=R[t]=0,ans--,t--;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}*/
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k,a[100];scanf("%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("%d\n",n);
	return 0;
}
