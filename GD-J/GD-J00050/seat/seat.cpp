#include<bits/stdc++.h>
using namespace std;


struct P{
	int s;
	int id;
};

P a[300];

bool cmp(P x,P y)
{
	if(x.s>y.s)
		return 1;
	else
		return 0;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i].s;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++)
//	{
//		cerr << a[i].s << " " << endl;
//	}
	int pos=-1;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			pos=i;
			//cerr << pos <<endl;
			break;
		}
	}
	int hang =pos % n;
	int lie=-1;
	if(pos%n!=0)
	{
		lie=pos/n+1;
	}
	else
	{
		lie=pos/n;
	}
	
	if(hang==0)
	{
		hang=n;
	}
	
	if(lie%2==0)
	{
		hang = n - hang;
	}
	cout << lie <<" "<< hang;
	return 0;
}
