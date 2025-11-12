#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
bool cmp(int x,int y){return x>y;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	int sum=a[1],q=1;
	for(int i=1;i<=n*m;i++) if(a[i]>sum) q++;
	int x=(q-1)/n+1,y;
	if(x&1) y=q-(x-1)*n;
	else y=x*n-q+1;
	printf("%d %d",x,y);
	return 0;
}
