#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int s,p;
}a[110];
bool cmp(node q,node w)
{
	return q.s>w.s;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i].s;
	int g=a[1].s,gp;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		a[i].p=i;
		if(a[i].s==g)gp=i;
	}
	int lie=ceil(gp*1.0/n);
	if(lie%2)
	{
		int hang=gp%n;
		if(hang==0)hang=n;
		cout<<lie<<' '<<hang;
		return 0;
	}
	else 
	{
		int hang=n+1-(gp%n);
		if(gp%n==0)
		hang=1;
		cout<<lie<<' '<<hang;
		return 0;
	}
	return 0;
}
