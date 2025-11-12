#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[1010],r=0,da=0,xi=0;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		if(i==1) r=a[i];
		else if(a[i]>r) da++;
		else if(a[i]<r) xi++;
	}
	int lie=da/n;lie++;
	int h=da%n;h++;
	if(lie%2==1) printf("%d %d",lie,h);
	else printf("%d %d",lie,n-h+1);
	return 0;
}
