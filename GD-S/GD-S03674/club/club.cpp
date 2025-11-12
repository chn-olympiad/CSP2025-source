#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e5+10;
struct node{
	ll a[3];
}d[N];
bool cmp(node x,node y){
	ll a[3]={x.a[0],x.a[1],x.a[2]},b[3]={y.a[0],y.a[1],y.a[2]};
	sort(a,a+3);sort(b,b+3);
	return a[2]-a[1]>b[2]-b[1];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
 	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 	ll T;cin>>T;while(T--){
 		ll n;cin>>n;
		for(ll i=1;i<=n;i++) for(ll j=0;j<3;j++) cin>>d[i].a[j];
		sort(d+1,d+1+n,cmp);
		ll cnt[3]={0,0,0},ans=0;
		for(ll i=1;i<=n;i++){
			ll j=max_element(d[i].a,d[i].a+3)-d[i].a,k=min_element(d[i].a,d[i].a+3)-d[i].a,l;
			if(cnt[j]!=n/2){
				ans+=d[i].a[j];
				cnt[j]++;
				continue;
			}
			if((j==0&&k==1)||(j==1&&k==0)) l=2;
			if((j==1&&k==2)||(j==2&&k==1)) l=0;
			if((j==0&&k==2)||(j==2&&k==0)) l=1;
			ans+=d[i].a[l];
			cnt[l]++;
		}
		cout<<ans<<"\n";
	}
 	return 0;
}/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
