#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull B=147;
const int N=5000009;
int n,q; char A[N],C[N];
map< pair< ull,pair<ull,ull> >,vector<ull> > M1;
unordered_map< ull,bool > M2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",&A);
		scanf("%s",&C);
		int len=strlen(A),j,k;
		for(j=0;j<len;j++)
			if(A[j]!=C[j])
				break;
		for(k=len-1;k>=0;k--)
			if(A[k]!=C[k])
				break;
		if(j==len) continue;
		ull o=0,p=0;
		ull Q=0,H=0;
		for(int l=j;l<=k;l++)
			o=o*B+A[l],p=p*B+C[l];
		for(int l=j-1;l>=0;l--) Q=Q*B+A[l];
		for(int l=k+1;l<len;l++) H=H*B+A[l];
		M1[{Q,{o,p}}].push_back(H);
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%s",&A);
		scanf("%s",&C);
		if(strlen(A)!=strlen(C))
		{
			printf("0\n");
			continue;
		}
		int len=strlen(A),j,k;
		for(j=0;j<len;j++)
			if(A[j]!=C[j])
				break;
		for(k=len-1;k>=0;k--)
			if(A[k]!=C[k])
				break;
		ull o=0,p=0;
		for(int l=j;l<=k;l++)
			o=o*B+A[l],p=p*B+C[l];
		ull Q=0,H=0; M2[H]=1;
		for(int l=k+1;l<len;l++)
			H=H*B+A[l],M2[H]=1;
		int ans=0;
		for(ull v:M1[{0,{o,p}}])
			ans+=M2[v];
		for(int l=j-1;l>=0;l--)
		{
			Q=Q*B+A[l];
			for(ull v:M1[{Q,{o,p}}])
				ans+=M2[v];
		}
		printf("%d\n",ans);
		H=0; M2[H]=0;
		for(int l=k+1;l<len;l++)
			H=H*B+A[l],M2[H]=0;
	}
	return 0;
}
