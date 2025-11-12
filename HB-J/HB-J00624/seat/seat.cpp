#include <bits/stdc++.h>
using namespace std;
struct d
{
	int cj,tf;
}a[102];
int m,n;
bool cmp(d x,d y)
{
	return x.cj>y.cj;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1].cj;
	a[1].tf=1;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i].cj;
		a[i].tf=0;
	}
	sort(a+1,a+n*m+1,cmp);
	int cnt;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].tf==1)
		{
			cnt=i;
			break;
		}
	}
	int f1=cnt/n+1,f2=cnt%n;
	if(f2==0)
	{
		f1--;
		f2=n;
	}
	if(f1%2==1)
	{
		cout<<f1<<' '<<f2;
	}
	else
	{
		cout<<f1<<' '<<n-f2+1;
	}
	return 0;
}
