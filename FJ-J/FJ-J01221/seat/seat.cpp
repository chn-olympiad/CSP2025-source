#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+1e2;
int n,m,x,y,r,pm;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>x; pm=1;
	for(int i=2;i<=n*m;i++)
	{
		cin>>y;
		if(y>x) pm++;
	}
	r=(pm-1)/n+1;
	cout<<r<<" ";
	if(r&1) cout<<pm-(r-1)*n;
	else cout<<n-(pm-(r-1)*n)+1;
}
//2 2
//99 100 97 98

//2 2
//98 99 100 97

//3 3
//94 95 96 97 98 99 100 93 92