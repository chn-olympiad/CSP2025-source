#include<bits/stdc++.h>
using namespace std;
int n,m;
struct st
{
	int sc,id;
} a[110];
bool kml(st b1,st b2)
{
	return b1.sc>b2.sc;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
		cin>>a[i].sc;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,kml);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			cout<<(i-1)/n+1<<" ";
			if(((i-1)/n+1)%2==1)
			{
				cout<<i-n*((i-1)/n);
			}
			else
			{
				cout<<n-(i-n)+1;
			}
			break;
		}
	}
    return 0;
}
