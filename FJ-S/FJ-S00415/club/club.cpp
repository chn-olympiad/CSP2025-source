#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const ll N=1e5+10;
ll _;
ll n,ans;
struct Node{
	ll num[3];
	ll pos;
}a[N];
queue<Node> lt;
priority_queue<pair<ll,ll> > q[3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	_=read();
	while(_--){
		ans=0;
		n=read();
		for (int i=1;i<=n;i++){
			a[i].num[0]=read();
			a[i].num[1]=read();
			a[i].num[2]=read();
			a[i].pos=i;
			lt.push(a[i]);
		}
		while(!lt.empty()){
			Node now=lt.front();
			lt.pop();
			bool flag=false;
			ll pos=0;
			for (int i=0;i<3;i++){
				if((long long)q[i].size()*2<n&&now.num[i]>=now.num[(i+1)%3]&&now.num[i]>=now.num[(i+2)%3]){
					q[i].push(make_pair(-min(now.num[i]-now.num[(i+1)%3],now.num[i]-now.num[(i+2)%3]),now.pos));
					flag=true;
					break;
				}
				if((long long)q[i].size()*2==n) pos=i;
			}
			if(flag) continue;
			ll maxn=-1,k=0;
			for (int i=0;i<3;i++){
				if(i==pos) continue;
				if(maxn<now.num[i]) maxn=now.num[i],k=i;
			}
			if(q[pos].top().first+now.num[pos]>maxn){
				ll d=q[pos].top().second;
				q[pos].pop();
				q[pos].push(make_pair(-min(now.num[pos]-now.num[(pos+1)%3],now.num[pos]-now.num[(pos+2)%3]),now.pos));
				if(a[d].num[(pos+1)%3]>a[d].num[(pos+2)%3]) q[(pos+1)%3].push(make_pair(-min(a[d].num[(pos+1)%3]-a[d].num[pos],a[d].num[(pos+1)%3]-a[d].num[(pos+2)%3]),d));
				else q[(pos+2)%3].push(make_pair(-min(a[d].num[(pos+2)%3]-a[d].num[pos],a[d].num[(pos+2)%3]-a[d].num[(pos+1)%3]),d));
			} else {
				q[k].push(make_pair(-min(now.num[k]-now.num[(k+1)%3],now.num[k]-now.num[(k+2)%3]),now.pos));
			}
		}
		for (int i=0;i<3;i++){
			while(!q[i].empty()) {
				ans+=a[q[i].top().second].num[i];
				q[i].pop();
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
