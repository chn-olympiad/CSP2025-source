#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,m;
struct st
{
	int x,id;
}a[N];
bool cmp(st a,st b)
{
	return a.x>b.x;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) 
	{
		scanf("%d",&a[i].x);a[i].id=i;
	}
	sort(a+1,a+1+(n*m),cmp);
	int k=0;
	for(int i=1;i<=n*m;i++) if(a[i].id==1) k=i;
	int p=(k%n==0?k/n:k/n+1),q=k-n*(p-1);
	if(p%2==0) q=n-q+1;
	printf("%d %d",p,q);
	return 0;
}