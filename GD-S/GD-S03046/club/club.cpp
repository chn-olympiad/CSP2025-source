#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
struct npc{
	ll d[4];
}a[N];
bool cmp(npc a,npc b){
	if(a.d[1]!=b.d[1])return a.d[1]>b.d[1];
	if(a.d[2]!=b.d[2])return a.d[2]>b.d[2];
	if(a.d[3]!=b.d[3])return a.d[3]>b.d[3];
}
ll n;
ll cnt[4];
ll sm;
ll dfs(ll now){
	if(now>n)return sm;
	ll maxn=0;
	for(ll i=1;i<=3;i++){
		if(cnt[i]+1>(n/2)){
			continue;
		}
		cnt[i]++;
		sm+=a[now].d[i];
		maxn=max(maxn,dfs(now+1));
		sm-=a[now].d[i];
		cnt[i]--;
	}
	return maxn;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;
	cin>>T;
	while(T--){
		sm=0;
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i].d[1]>>a[i].d[2]>>a[i].d[3];
		}
		sort(a+1,a+1+n,cmp);
		cout<<dfs(1)<<'\n';
	}
	return 0;
}
