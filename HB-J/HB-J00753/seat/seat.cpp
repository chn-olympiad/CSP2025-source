#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[105],Rscore,idx;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int t=n*m;
	for (int i=1;i<=t;i++)
		cin >> a[i];
	Rscore=a[1];
	sort(a+1,a+t+1,cmp);
	for (int i=1;i<=t;i++)
		if (a[i]==Rscore) idx=i;
	int r=0,c=0;
	if (idx%n==0) c=idx/n;
	else c=idx/n+1;
	if (idx%n==0)
	{
		if (c%2) r=n;
		else r=1;
	}
	else
	{
		if (c%2) r=(idx%n);
		else r=n-(idx%n)+1;
	}
	cout <<c<<" "<<r;
	return 0;
}
