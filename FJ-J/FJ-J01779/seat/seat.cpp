#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int v[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int t=1;
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&v[i]);
		if(i!=1&&v[i]>v[1]) t++; 
	}
	int l,h;
	if(t%n==0) l=t/n;
	else l=t/n+1;
	if(l%2==1) 
	{
		h=t%n;
		if(h==0) h=n;
	}
	else h=n-t%n+1;
	printf("%d %d\n",l,h);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
