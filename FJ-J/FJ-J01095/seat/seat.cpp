#include<bits/stdc++.h>
int main(void)
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,mr=0;
	scanf("%d%d%d",&n,&m,&r);
	for(int i=1; i<n*m; ++i)
	{
		int ai;scanf("%d",&ai);
		if(ai>r)++mr;
	}
	int le=mr/n+1,hg=((le&1)?(mr%n):(n-1-(mr%n)))+1;
	printf("%d %d",le,hg);
	return 0;
}
