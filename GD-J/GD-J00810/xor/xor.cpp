#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll a[N];
ll n,k;
ll ans=1;
ll pre[N];
/*
4 0
2 1 0 3
4 3
2 1 0 3
4 3
2 1 0 3
*/
pair<ll,ll> c[N];
bool cmp(pair<ll,ll>x,pair<ll,ll>y){
	if(x.first!=y.first)return x.first<y.first;
	return (x.second-x.first+1)<(y.second-y.first+1);
}
ll cnt1,cnt0;
bool tp(){
	for(int i=1;i<=n;i++){
		if(a[i]>1)	return 0;
	}
	return 1;
}
bool tpA(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1)	return 0;
	}
	return 1;
}
ll l1;
bool vis[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)	cnt1++;
		if(a[i]==0)	cnt0++;
	}
	for(ll i=1;i<n;i++){
		if(vis[i]==0&&a[i]==1&&a[i+1]==1){
			l1++;
			i++;
		}
	}
	if(k==0&&tpA()){
		cout<<n/2;
		return 0;
	}
	if(k==1&&tp()){
		cout<<cnt1;
		return 0;
	}
	if(k==0&&tp()){
		cout<<cnt0+l1;
		return 0;
	}
	ll cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ll res=a[i];
			for(int l=i+1;l<=j;l++){
				res^=a[l];
			}
			if(res==k){
				c[++cnt]={i,j};
			}
		}
	}
	sort(c+1,c+cnt+1,cmp);
//	for(int i=1;i<=cnt;i++){
//		cout<<c[i].first<<" "<<c[i].second<<endl;
//	}
	ll ly=c[1].second;
	for(int i=2;i<=cnt;i++){
		if(c[i].first>ly){
			ly=c[i].second;
			ans++;
//			cout<<c[i].first<<" "<<c[i].second<<endl;
		}
	}
	cout<<ans; 
	return 0;
}
