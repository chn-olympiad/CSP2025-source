#include<bits/stdc++.h>
using namespace std;
struct node
{
	int id,score;
}a[105];
bool cmp(node x,node y)
{
	return x.score>y.score;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		a[i].id=i;
		cin>>a[i].score;
	}
	sort(a+1,a+n*m+1,cmp);
	
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1) 
		{
			int lie=ceil(1.0*i/n);
			int hang;
			if(lie%2==1)
			{
				hang=i-(lie-1)*n;
			}
			else
			{
				hang=n+1-(i-(lie-1)*n);
			}
			cout<<lie<<' '<<hang;
		}
	}
	return 0;	
} 