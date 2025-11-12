#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,x,y,cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x;
	for(int i=2;i<=n*m;i++){
		scanf("%lld",&y);
		cnt+=(y>x);
	}
	ll a=ceil(cnt*1.0/(2*n)),b=cnt%(2*n),c,d;
	if(b<=n&&b) c=2*a-1,d=b;
	else{
		c=2*a;
		if(b) d=2*n+1-b;
		else d=1;
	}
	cout<<c<<" "<<d<<"\n";

	return 0;
}
