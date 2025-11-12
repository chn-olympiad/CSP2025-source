#include<bits/stdc++.h>
using namespace std;
struct node
{
	int p,id;
}a[105];
bool cmp(node a,node b)
{
	return a.p>b.p;
}
int n,m,l,ansn,ansm=1,k=1,x;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	l=n*m;
	for(int i=1;i<=l;i++)
	{
		a[i].id=i;
		cin>>a[i].p;
	}
	sort(a+1,a+l+1,cmp);
	for(int i=1;i<=l;i++)
	{
		ansn+=k;
		if(ansn>n)
		{
			ansn=n;
			ansm++;
			k=-1;
		}
		else if(ansn<1)
		{
			ansn=1;
			ansm++;
			k=1;
		}
		if(a[i].id==1)
		{
			cout<<ansm<<" "<<ansn;
			break;
		}
	}
	return 0;
} 
