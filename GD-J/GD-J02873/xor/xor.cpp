#include<bits/stdc++.h>
#define ll long long


using namespace std;

const int N=5e5+10;
int n,k;
int a[N];
int sum[N]={0};
int t[1200000];

struct e{
	int l,r;
}c[N];

int cnt=0;

int f[N];

int main()
{
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	
	for(int i=1;i<=n;++i)
	{
		if(t[sum[i]]!=0)
		{
			c[++cnt]={t[sum[i]]+1,i};
		}
		else if(a[i]==k) c[++cnt]={i,i};
		else if(sum[i]==k)
		{
			c[++cnt]={1,i};
		}
		
		t[sum[i]^k]=i;
	}
	
	/*for(int i=1;i<=cnt;++i)
	{
		printf("%d %d\n",c[i].l,c[i].r);
	}*/
	
	int nw=1;
	
	for(int i=1;i<=n;++i)
	{
		if(i==c[nw].r)
		{
			f[i]=max(f[i-1],f[c[nw].l-1]+1);
			++nw;
		}
		else f[i]=f[i-1];
	}
	
	printf("%d",f[n]);
	
	return 0;
}
