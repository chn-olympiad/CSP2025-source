#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct node{
	ll id,nub;
};
bool cmp(const node &x,const node &y){return x.nub>y.nub;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	ll n,m,ans;cin>>n>>m;
	vector<node> a(n*m+1);
	for(ll i=1;i<=n*m;i++)a[i].id=i,cin>>a[i].nub;
	sort(begin(a)+1,end(a),cmp);
	for(ll i=1;i<=n*m;i++)if(a[i].id==1)ans=i;
	if((ans/n+(ans%n>0?1:0))%2){
		if(ans%n)cout<<ans/n+1<<' '<<ans%n;
		else cout<<ans/n<<' '<<n;
	}
	else{
		if(ans%n)cout<<ans/n+1<<' '<<n-(ans%n)+1;
		else cout<<ans/n<<' '<<1;
	}
	return 0;
}