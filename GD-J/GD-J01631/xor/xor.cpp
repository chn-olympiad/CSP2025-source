#include<bits/stdc++.h>
using namespace std;
unsigned int n,k,cnt,a[500005],pre[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(unsigned int i=1;i<=n;i++)
		scanf("%d",&a[i]),pre[i]=pre[i-1]^a[i];
	for(unsigned int l=1;l<=n;l++)
		for(unsigned int r=l;r<=n;r++)
			if((pre[r]^pre[l])==k)
			{
				cnt++,l=r;
				break;
			}
	cout<<cnt;
	return 0;
}
