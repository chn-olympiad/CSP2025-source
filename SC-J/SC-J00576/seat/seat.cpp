#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m,lz=0; cin>>n>>m;
	vector<int> a(n*m);
	for(auto &x:a) cin>>x;
	lz=a[0];
	sort(a.begin(),a.end(),greater<int>());
	for(int ax=0,x=0,y=0,xk=1;ax<n*m;ax++)
	{
		if(a[ax]==lz)
		{
			cout<<y+1<<' '<<x+1;
			return 0;
		}
		x+=xk;
		if(x>=n)
		{
			y++; x=n-1;
			xk=-1;
		}
		else if(x<0)
		{
			y++; x=0;
			xk=1;
		}
	}
	return 0;
}