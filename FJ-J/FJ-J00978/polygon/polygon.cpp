#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;
ll a[5010],qz[5010];
bool cmp(ll a,ll b){
	return a>b;
}
void ss(ll x,ll i,ll m,ll num){
	if(x<=m) return;
	if(i==n+1){
		ans++;
		return;
	}
	ss(x-a[i],i+1,m,num+a[i]);
	ss(x,i+1,m,num);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1,cmp);
	for(int i=n;i>=1;i--){
		qz[i]=a[i]+qz[i+1];
	}
	for(int i=1;i<=n;i++){
		ll maxx=a[i];
		if(qz[i+1]<=maxx) {
			continue;
		}
		ss(qz[i+1],i+1,maxx,0);
	}
	cout<<ans;
	return 0;
} 
