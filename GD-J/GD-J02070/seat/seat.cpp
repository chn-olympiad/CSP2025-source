#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n,m,a[100],x,i;
bool cmp(int z,int x)
{
	return z>x;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x;
	a[0]=x;
	for(i=1; i<n*m; i++)cin>>a[i];
	sort(a,a+n*m,cmp);
	for(i=0; a[i]!=x ;i++);
	i++;
	
	int z=(i+n-(i%n==0 ? n : i%n))/n;
	int x=i%(n*2);
	cout<<z<<' '<<(x<=n ? x==0 ? n : x : i%n+1);
	return 0;
}
