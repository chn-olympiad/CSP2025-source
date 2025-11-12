#include<bits/stdc++.h>
using namespace std;
long long a[5005];
long long b[5005];
const int Maxk=1050000;
long long tree[Maxk+5];
inline long long lowbit(long long x){return x&(-x);}
void add(long long x, long long y)
{
	while(x<=Maxk)
	{
		tree[x]+=y;
		x+=lowbit(x);
	}
}
long long qu(int x)
{
	long long ans=0;
	while(x>0)
	{
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans; 
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k;
	scanf("%d%d",&n,&k);
	add(1,1);
	int ans=0;
	int r=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		b[i]=b[i-1]^a[i];
		long long fi=b[i]^k;
		long long id=qu(fi+1)-qu(fi);
		if(id<r)
		{
			add(fi+1,-id);
		}
		else
		{
			r=i+1;
			ans++;
		}
		b[i]=b[i-1]^a[i];
		id=qu(b[i]+1)-qu(b[i]);
		add(b[i]+1,i+1-id);
	}
	printf("%d",ans);
	return 0;
}
/*
4 0
2 1 0 3
*/
