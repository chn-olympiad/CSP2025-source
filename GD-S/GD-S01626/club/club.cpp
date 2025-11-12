#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
ll n,a[N][4];
priority_queue<ll,vector<ll>,greater<ll> > x,y,z;
void solve(){
	scanf("%lld",&n);
	ll ans=0;
	while(!x.empty())x.pop();
	while(!y.empty())y.pop();
	while(!z.empty())z.pop();
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			ans=ans+a[i][1];
			x.push(a[i][1]-max(a[i][2],a[i][3]));
			if(x.size()>n/2){
				ans=ans-x.top();
				x.pop();
			}
		}else{
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				ans=ans+a[i][2];
				y.push(a[i][2]-max(a[i][1],a[i][3]));
				if(y.size()>n/2){
					ans=ans-y.top();
					y.pop();
				}
			}else{
				ans=ans+a[i][3];
				z.push(a[i][3]-max(a[i][1],a[i][2]));
				if(z.size()>n/2){
					ans=ans-z.top();
					z.pop();
				}
			}
		}
	}
	printf("%lld\n",ans);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--)solve();
	return 0;
} 
