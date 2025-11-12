#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll Md=998244353;
ll n,a[5050],ans;
bool hit=1;
bool cmp(ll p,ll q){
	return p<q; 
}
void Search(ll i,ll cnt,ll mx,ll s){
	if(i!=n+1){
		Search(i+1,cnt+a[i],max(mx,a[i]),s+1);
		Search(i+1,cnt,mx,s);
	}else{
		if(s>=3&&cnt>2*mx) ans=(ans+1)%Md;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) hit=0;
	}
	if(hit){
		ans=1;
		for(ll i=1;i<=n;i++){
			ans=(ans*2)%Md;
		}
		ans=(ans+Md-1-n-n*(n-1)/2)%Md;
		cout<<ans;
		return 0;
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	Search(1,0,0,0);
	cout<<ans;
	return 0;
}
