#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
struct node{ll x,y,z;}a[N];
int cnt[3],n,T;
int id(int i){
	return (a[i].x>=a[i].y&&a[i].x>=a[i].z)?0:(a[i].y>=a[i].x&&a[i].y>=a[i].z)?1:2;
}
void solve(){
	scanf("%d",&n);
	ll ans(0);
	cnt[0]=cnt[1]=cnt[2]=0;
	for(int i=1;i<=n;++i){
		scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
		cnt[id(i)]++;
		ans+=max({a[i].x,a[i].y,a[i].z});
	}
	if(max({cnt[0],cnt[1],cnt[2]})<=n/2){
		printf("%lld\n",ans);
		return;
	}
	priority_queue<ll,vector<ll>,greater<ll>>q;
	if(cnt[0]>=cnt[1]&&cnt[0]>=cnt[2]){
		int tot=cnt[0]-n/2;
		for(int i=1;i<=n;++i){
			if(id(i)!=0)continue;
			q.push(min(a[i].x-a[i].y,a[i].x-a[i].z));
		}
		while(tot--){
			ans-=q.top();
			q.pop();
		}
	}
	else if(cnt[1]>=cnt[0]&&cnt[1]>=cnt[2]){
		int tot=cnt[1]-n/2;
		for(int i=1;i<=n;++i){
			if(id(i)!=1)continue;
			q.push(min(a[i].y-a[i].x,a[i].y-a[i].z));
		}
		while(tot--){
			ans-=q.top();
			q.pop();
		}
	}
	else{
		int tot=cnt[2]-n/2;
		for(int i=1;i<=n;++i){
			if(id(i)!=2)continue;
			q.push(min(a[i].z-a[i].x,a[i].z-a[i].y));
		}
		while(tot--){
			ans-=q.top();
			q.pop();
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
} 

