#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=20;
struct node{
	ll v,id;
}a[N*N];
ll n,m;
bool cmp(node x,node y){
	return x.v>y.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i].v;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	ll x=1,y=1;
	for(ll i=1;i<=n*m;i++){
		if(a[i].id==1){
			cout<<y<<" "<<x;
			break;
		}
		if(x==1 && y%2==0) y++;
		else if(x==n && y%2==1) y++;
		else if(y%2==1) x++;
		else x--;
	}
	return 0;
}
