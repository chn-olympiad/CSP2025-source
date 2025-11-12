#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int s,num;
}a[144];
bool p(node x,node y)
{
	return x.s>y.s;
}
bool b(node x,node y)
{
	return x.s<y.s;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1,j=1;i<=n*m;i++)
		scanf("%d",&a[i].s),a[i].num=j++;
	sort(a+1,a+n*m+1,p);
	for(int i=2;i<=m;i++)
		if(i%2==0) sort(a+1+(i-1)*n,a+i*n,b);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(a[(i-1)*n+j].num==1) cout<<i<<' '<<j;
	return 0;
}
