#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll n;
struct node{
	ll p[4];
	ll mn,mx,mid;
}a[N];
bool cmp(node u,node v){
	return u.p[u.mx]-u.p[u.mid]>v.p[v.mx]-v.p[v.mid];
}
ll cnt[4];
ll ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ll _;
	cin>>_;
	while(_--){
		cin>>n;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		ans=0;
		ll mxbc=0;
		for(ll i=1;i<=n;i++){
			cin>>a[i].p[1]>>a[i].p[2]>>a[i].p[3];
			mxbc=max(mxbc,max(a[i].p[2],a[i].p[3]));
			if(a[i].p[1]<a[i].p[2]){
				if(a[i].p[2]<a[i].p[3]){
					a[i].mn=1;
					a[i].mid=2;
					a[i].mx=3;
				}else{
					a[i].mx=2;
					if(a[i].p[1]<a[i].p[3]){
						a[i].mid=3;
						a[i].mn=1;
					}else{
						a[i].mid=1;
						a[i].mn=3;
					}
				}
			}else{
				if(a[i].p[2]>a[i].p[3]){
					a[i].mn=3;
					a[i].mid=2;
					a[i].mx=1;
				}else{
					a[i].mn=2;
					if(a[i].p[1]>a[i].p[3]){
						a[i].mid=3;
						a[i].mx=1;
					}else{
						a[i].mid=1;
						a[i].mx=3;
					}
				}
			}
		}
		sort(a+1,a+n+1,cmp);
		for(ll i=1;i<=n;i++){
			if(cnt[a[i].mx]==n/2){
				cnt[a[i].mid]++;
				ans+=a[i].p[a[i].mid];
			}else{
				cnt[a[i].mx]++;
				ans+=a[i].p[a[i].mx];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
