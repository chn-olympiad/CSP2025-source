#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,l;
struct node{
	int s;
	int e;
	int m;
}a[N];
bool cmp(node x,node y)
{
	return x.m<y.m;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&l);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].s,&a[i].e,&a[i].m);
	}
	sort(a+1,a+n+1,cmp);
	int sum=0;
	for(int i=1;i<n;i++)
	{
		sum+=a[i].m;
	}
	printf("%d",sum);
	return 0;
}
