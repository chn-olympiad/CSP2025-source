#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+15;
int n;
int read(){
	int x=0,w=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-'){w=-1;}c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*w;
}
int cnt[3],id;
ll ans,a[3];
priority_queue<ll>q[3];
void init(){
	for(int i = 0;i < 3;++i){
		while(!q[i].empty())q[i].pop();
	}
	cnt[0]=cnt[1]=cnt[2]=0;
	ans=0;
}
void solve(){
	init();
	n=read();
	for(int i = 1;i <= n;++i){
		a[0]=read(),a[1]=read(),a[2]=read();
		if(a[0]>=a[1]&&a[0]>=a[2]){
			cnt[0]++;id=0;
			q[0].push(max(a[1],a[2])-a[0]);
		}
		else if(a[1]>=a[0]&&a[1]>=a[2]){
			cnt[1]++;id=1;
			q[1].push(max(a[0],a[2])-a[1]);
		}
		else {
			cnt[2]++;id=2;
			q[2].push(max(a[0],a[1])-a[2]);
		}
		ans+=a[id];
		if(cnt[id]<=n/2)continue;
		ans+=q[id].top();
		q[id].pop();
		cnt[id]--;
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)solve();
	return 0;
} 
