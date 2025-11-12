#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define PLL pair<long long,long long>
#define PB push_back
const int N=114;
ll m,n;
ll a[N],b[N][N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%lld",a+i);
	ll k=a[1],rnk=0;
	sort(a+1,a+n*m+1); 
	ll x=1,y=1,p;
	for(int i=n*m;i>=1;i--) if(a[i]==k) {
		rnk=n*m-i+1;
		break;
	}
//	cout<<rnk<<endl;
	if(rnk%n){
		x=rnk/n+1;
		p=rnk/n*m;
		if(x%2)	y=rnk%n;
		else y=m-rnk%n+1;	
	}
	else {
		x=rnk/n;
		if(x%2) y=m;
		else y=1;
	}
	printf("%lld %lld",x,y);
	return 0;
	}
/**/

