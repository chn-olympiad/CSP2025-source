#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005],id[1005];
void qsort(int l,int r)
{
	if(l>=r) return;
	int i=l,j=r,mid=a[rand()%(r-l+1)+l];
	while(i<=j)
	{
		while(a[i]>mid) i++;
		while(a[j]<mid) j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			swap(id[i],id[j]);
			i++; j--;
		}
	}
	qsort(i,r); qsort(l,j);
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	srand(time(0));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		id[i]=i;
	}
	qsort(1,n*m);
	int x=0,y=1;
	for(int i=1;i<=n*m;i++)
	{
		if(y%2==1) x++;
		else x--;
		if(x>n) x=n,y++;
		if(x<1) x=1,y++;
		if(id[i]==1)
		{
			printf("%d %d",y,x);
			return 0;
		}
	}
	return 0;
}

