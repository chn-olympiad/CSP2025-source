#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s=0;
	int p,x;
	cin>>p;
	for(int i=1;i<n*m;i++)
	{
		cin>>x;
		if(x>p) s++;
	}
	int c=s/n+1;
	int r;
	if(c%2==1) r=s%n+1;
	else r=n-(s%n);
	cout<<c<<' '<<r;
	return 0;
}
