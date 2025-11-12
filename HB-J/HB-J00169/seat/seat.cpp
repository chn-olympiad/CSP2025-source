#include <bits/stdc++.h>
using namespace std;
int n,m,a,cnt=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	cin>>a;
	for(int i=2;i<=k;i++)
	{
		int t;
		cin>>t;
		if(t>a)cnt++;
	}
	int c=cnt/n+1,r;
	if(c%2==1)
		r=cnt%n+1;
	if(c%2==0)
		r=n-cnt%n;
	cout<<c<<" "<<r;
	return 0;
}
