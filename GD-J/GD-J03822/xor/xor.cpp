#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 5e5+5;
ll vis[maxn],cnt = 1,ans = 0,q = 0;
struct stu{
	ll ix,jx;
}dis[maxn];
bool cmp(stu a,stu b){
	return a.jx<b.jx;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	for(ll i = 1;i<=n;i++){
		cin>>vis[i];
		vis[i] = vis[i]^vis[i-1];
	}
	for(ll i = 1;i<=n;i++){
		for(ll j = i;j<=n;j++){
			ll n = vis[i-1]^vis[j];
			if(n == k){
				dis[cnt].ix = i;
				dis[cnt].jx = j;
				cnt++;
				
			}
		}
	}
	sort(dis+1,dis+cnt,cmp);
	for(ll i = 1;i<cnt;i++){
		if(q<dis[i].ix){
			q = dis[i].jx;
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
