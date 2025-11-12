#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[1010];
ll key=0,s[100][100];

bool cmp(ll x,ll y){
	return x>y;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n*m;i++) scanf("%lld",&a[i]);
	key=a[1];
	sort(a+1,a+1+n*m,cmp);
	ll x=1,y=1;
	for(ll i=1;i<=n*m;i++){
		s[x][y]=a[i];
		if(s[x][y]==key){
			cout<<y<<" "<<x;
			return 0;
		}
		if(x==n&&y%2==1) y++;
		else if(x==1&&y%2==0) y++;
		else if(y%2==1) x++;
		else if(y%2==0) x--;
	}
	return 0;
}
/*
2 2
99 100 97 98
*/
/*
2 2
98 99 100 97
*/
/*
3 3
94 95 96 97 98 99 100 93 92
*/
