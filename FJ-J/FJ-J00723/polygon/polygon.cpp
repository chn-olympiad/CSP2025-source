#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll Mod=998244353;
ll n,a[5010],ans;
void f(ll x,ll y,ll sum){
	ll l=y+1,r=n,mid=(l+r+1)>>1;
	while(l<r){
		if(a[mid]<sum)l=mid;
		else r=mid-1;
		mid=(l+r+1)>>1;
	}
	if(l>n)return;
	if(a[l]<sum){
		ans=(ans+(l-y));
		ans%=Mod;
//		cout<<(l-y)<<" "<<x<<" "<<y<<" "<<l<<" "<<cnt<<'\n';
	}
	for(int i=y+1;i<=n;++i){
		f(x,i,sum+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	srand(time(0));
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		swap(a[i],a[rand()%n+1]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;++i){
		for(int j=i+1;j<=n-1;++j){
			f(i,j,a[i]+a[j]);
		}
	}
	cout<<ans;
	return 0;
}
