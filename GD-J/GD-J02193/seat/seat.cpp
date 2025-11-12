#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll i,n,m,s,x,y,r,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	s=n*m;
	for(i=1;i<=s;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+s+1);
	for(i=1;i<=s;i++) if(r==a[i])
	{
		r=s-i+1;
		break;
	}
	y=(r-1)/n+1;
	if(y&1) x=r-(y-1)*n;
	else x=m-r+(y-1)*n+1;
	cout<<y<<" "<<x;
	return 0;
}
