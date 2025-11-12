#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],cnt=0;
void dfs(int r,int l)
{
	if(r>=n||l>=n)
	return;
	for(int i=1;i<=n;i++)
	{
		int s=sum[r]|sum[l],p=sum[r]&sum[l];
		if((s==k)&&(p==k))
		{
			cnt++;
			l=r+1;
			r=l;
			dfs(r,l);
		}
		else
		r++;
	}
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    cin>>a[1];
    sum[1]=a[1];
    for(int i=2;i<=n;i++)
    {
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	dfs(1,1);
	cout<<cnt;
    return 0;
}
