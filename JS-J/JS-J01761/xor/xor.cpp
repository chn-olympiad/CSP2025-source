#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r,num;
}b[500005];
int n,k,a[500005],cnt,ans,ll,rr;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{		
			b[++cnt].l = min(i,j);
			b[cnt].r = max(i,j);
			int c=a[min(i,j)];
			for(int z=min(i,j)+1;z<=max(i,j);z++)
			{
				c = c xor a[z];
			}
			b[cnt].num = c;
		}
	}
	ll =-1;
	rr=-1;
	for(int i=1;i<=cnt;i++)
	{
		if(b[i].num==k and b[i].l>rr and b[i].r>rr)
		{
			ll = b[i].l;
			rr = b[i].r;
			ans++;
		}
			
	}
	cout<<ans;
	return 0;
}


