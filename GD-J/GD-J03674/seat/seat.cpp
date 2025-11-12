#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],k,d=1;
struct node{int l,h;}f[110];
bool cmp(int a,int b){return a>b;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	{
		if(i%2)f[a[d]]={i,j};
		else f[a[d]]={i,m-j+1};
		if(a[d]==k){printf("%d %d\n",f[a[d]].l,f[a[d]].h);return 0;}
		d++;
	}
	return 0;
}
