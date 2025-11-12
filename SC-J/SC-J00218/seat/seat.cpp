#include<bits/stdc++.h>
using namespace std;
int m,n,mb,mc=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&mb);
	for(int i=1;i<=m*n-1;i++)
	{
		int x;
		scanf("%d",&x);
		if(x>mb)mc++;
	}
	int l=((mc-1)/n)+1;
	mc--;
	mc%=n;
	mc++;
	if(l%2==0)mc=n-mc+1;
	printf("%d %d",l,mc);
	return 0;
}

