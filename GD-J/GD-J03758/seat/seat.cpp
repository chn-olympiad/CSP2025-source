#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[110],op,o;
bool cmp(ll q,ll p){
	return q>p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>op;
	a[1]=op;
	for(ll i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(ll i=1;i<=n*m;i++){
		if(a[i]==op){
			o=i;
			break;
		}
	}
	ll x=1,y=1,z=0,f=0;
	while(o>0){
		if(o>=n&&z%2==0&&f==0)x+=n-1,o-=n,z++,f=1;
		else if(o>=n&&z%2==0&&f==1)x-=n-1,o-=n,z++,f=0;
		else if(o<n&&z%2==0&&f==0)x+=o-1,o=0;
		else if(o<n&&z%2==0&&f==1)x-=o-1,o=0;
		else if(z%2==1)y++,z++;
	}
	cout<<y<<' '<<x;
	return 0;
}
