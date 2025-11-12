#include<bits/stdc++.h>
using namespace std;
int n,m,k,id;
int a[505];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	k=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
		if(a[i]==k)
		{
			id=n*m-i+1;
			break;
		}
	int t=id/n,r=id-n*t;
	if(!r)
		printf("%d %d",t,((t%2)?n:1));
	else
		printf("%d %d",t+1,((t%2)?m-r+1:r));
	return 0;
}
