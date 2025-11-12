#include <bits/stdc++.h>
using namespace std;
struct node
{
	long long idx,x;
}a[110];
long long n,m,nowx=1,nowy=1;
bool cmp(node xx,node yy)
{
	return xx.x>yy.x;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1; i<=n*m; i++)
	{
		cin>>a[i].x;
		a[i].idx=i;
	}
	sort(a+1,a+n*m+1LL,cmp);
	for(int i=1; i<=n*m; i++)
	{
		if(a[i].idx==1)
		{
			cout<<nowy<<" "<<nowx;
			return 0;
		}
		if(nowy%2==1)
		{
			 nowx++;
			 if(nowx==n+1) nowx=n,nowy++;
		}
		else
		{
			nowx--;
			if(nowx==0) nowx=1,nowy++;
		}
	}
	return 0;
}