#include<bits/stdc++.h>
using namespace std;
int s[500005],a[500005];
int T[2000005],f[500005];
int main()
{
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout); 
	memset(T,-1,sizeof(T));
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),s[i]=s[i-1]^a[i];
	T[0]=0;
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		if(T[s[i]^k]!=-1) f[i]=max(f[i],T[s[i]^k]+1);
		T[s[i]]=f[i];
	}
	printf("%d",f[n]);
}
