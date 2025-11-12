#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
struct N{
	ll v,id;
	friend bool operator<(N a,N b){return a.v>b.v;}
}a[100010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++)cin>>a[i].v;
	a[1].id=1;
	sort(a+1,a+n*m+1);
	ll x=1,y=1,pos=1,jia=1;
	while(pos<=n*m){
		if(a[pos].id==1){
			cout<<y<<" "<<x<<"\n";
			return 0;
		}
		if(jia==1&&x==n){
			y++,jia=-1,pos++;
			continue;
		}
		if(jia==-1&&x==1){
			y++,jia=1,pos++;
			continue;
		}
		x+=jia,pos++;
	}
	return 0;
} 
