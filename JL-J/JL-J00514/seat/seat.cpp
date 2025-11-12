#include<bits/stdc++.h>
using namespace std;
set<int> s;
int x,c,r,n,m;
int main()
{	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		cin>>x;
		s.insert(x);
	}
	for(auto c:s)
	cout<<c<<" ";
	
	return 0;
}
