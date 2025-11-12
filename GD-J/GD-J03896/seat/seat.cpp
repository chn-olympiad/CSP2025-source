#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct nod
{
	int id,x;
};
const int NMR=101;
nod a[NMR];
bool cmp(nod x,nod y)
{
	return x.x>y.x;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,d;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		a[i].id=i;
		cin>>a[i].x;
	}
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=n*m;i++)
		if(a[i].id==1) d=i;
	const int h=ceil(1.0*d/n);
	cout<<h<<" ";
	if(h%2) cout<<d-(h-1)*n;
	else cout<<n+1-(d-(h-1)*n); 
	return 0;
}
