#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int s[500005];
int lst[2097156];
int ls[500005];
int f[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	scanf("%d%d",&n,&k);
	memset(lst,-1,sizeof(lst));
	lst[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
		if(lst[s[i]^k]!=-1) ls[i]=lst[s[i]^k]+1;
		else ls[i]=-1;			
		lst[s[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		if(ls[i]!=-1) f[i]=max(f[i],f[ls[i]-1]+1);
	}
	printf("%d",f[n]);
}
