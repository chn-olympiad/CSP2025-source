#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=20;
int n,m,a1;
array<int,N*N> a;
int r,c;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	a1=a[1];
	sort(a.begin()+1,a.begin()+n*m+1);
	int rnk=lower_bound(a.begin(),a.begin()+n*m+1,a1)-a.begin();
	rnk=n*m-rnk+1;
	c=(rnk+n-1)/n;
	r= rnk%n!=0 ? rnk%n : n;
	if(c%2==0) r=n-r+1;
	cout<<c<<' '<<r; 
	return 0;
}
