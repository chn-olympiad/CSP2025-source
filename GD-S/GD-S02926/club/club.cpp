#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
const ll N=1e5+10;
using namespace std;
ll t,op,ra,rb,rc,ans,mid;
ll a[N],b[N],c[N];
void dfs(ll x,ll num,ll bia){
	if(op==bia) {
		ans=max(ans,num);
		return ;
	}
	op++;
	if(ra<mid){
		ra++;
		dfs(x+1,num+a[x],bia);
		ra--;
	}
	if(rb<mid){
		rb++;
		dfs(x+1,num+b[x],bia);
		rb--;
	}
	if(rc<mid){
		rc++;
		dfs(x+1,num+c[x],bia);
		rc--;
	}
	op--;
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	ll n;
	while(t--){
		cin>>n;
		mid=n/2;
		ra=0,rb=0,rc=0,ans=0;
		for(ll i=1;i<=n;++i)
			cin>>a[i]>>b[i]>>c[i];
		dfs(1,0,n);
		cout<<ans<<endl;
	}
//	cout<<x.top().first;
	
	return 0;
} 
