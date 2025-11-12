#include<bits/stdc++.h>
using namespace std;
int t,n,h[4],k1,k2,k3,tot;
long long a[100010],b[100010],c[4],d[100010],sum;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		h[1]=h[2]=h[3]=tot=sum=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			k1=k2=0;
			scanf("%lld%lld%lld",&c[1],&c[2],&c[3]);
			for (int j=1;j<=3;j++)
			if (j==1||c[j]>c[k1]) k1=j;
			for (int j=1;j<=3;j++)
			if (j!=k1&&c[k2]<c[j]) k2=j;
			h[k1]++;a[i]=k1;b[i]=c[k1]-c[k2];sum+=c[a[i]];
		}
		for (int j=1;j<=3;j++)
		if (j==1||h[j]>h[k3]) k3=j;
		if (h[k3]>n/2) 
		{
			for (int i=1;i<=n;i++)
			if (a[i]==k3) d[++tot]=b[i];
			sort(d+1,d+tot+1);
			for (int i=1;i<=h[k3]-n/2;i++) sum-=d[i];
		}
		printf("%lld\n",sum);
	}
}
