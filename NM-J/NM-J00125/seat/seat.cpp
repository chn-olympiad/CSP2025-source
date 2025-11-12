#include<bits/stdc++.h>
using namespace std;
int n,m,q,w,sum=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	sum=1;
	for(int i=2;i<=n*m;i++)
	{
		scanf("%d",&w);
		if(w>q)sum++;
	}
	int i=1;
	while(sum>n){i++;sum-=n;}
	printf("%d %d",i,i%2 ? sum:n-sum+1);
	fclose(stdin);
	fclose(stdout);
    return 0;
}
