#include<bits/stdc++.h>
using namespace std;
int n,m,s[505],c[505],p[505],ans;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%1d",&s[i]);
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	for(int i=1;i<=n;++i)p[i]=i;
	do{
		int k=0;
		for(int i=1;i<=n;++i)k+=(s[i]&&i-k-1<c[p[i]]);
		ans+=(k>=m);
	}while(next_permutation(p+1,p+n+1));
	printf("%d\n",ans);
	return 0;
}

