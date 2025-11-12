#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n,m;
ll a;
ll index=1;
ll c,r; 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<n*m;i++)
	{
		int t;
		cin>>t;
		if(t>a) index++;
	}
	
	c=index/n;
	r=index%n;
	if(index%n!=0) c++;
	else r=n;
	if(c%2==0) r=n-r+1;

	cout<<c<<" "<<r;
	return 0;
}
/*3 3
  94 95 96 97 98 99 100 93 92*/

