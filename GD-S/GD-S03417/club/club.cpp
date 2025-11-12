#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int v,i;
};
struct p{
	node d[3];
}a[N];
struct pq{
	int id,d;
	friend bool operator >(pq x,pq y){
		return x.d>y.d;
	}
};
bool c1(node x,node y){
	return x.v>y.v;
}
bool c2(p x,p y){
	return x.d[0].v<y.d[0].v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].d[0].v>>a[i].d[1].v>>a[i].d[2].v;
			a[i].d[0].i=0,a[i].d[1].i=1,a[i].d[2].i=2;
			sort(a[i].d,a[i].d+3,c1);
		}
		sort(a+1,a+n+1,c2);
		int ans=0;
		priority_queue<pq,vector<pq>,greater<pq> > q[3];
		for(int i=1;i<=n;i++){
			p x=a[i];
			if(q[x.d[0].i].size()<n/2){
				q[x.d[0].i].push({i,x.d[0].v});
			}
			else{
				int t=q[x.d[0].i].top().id,v=q[x.d[0].i].top().d;
				if(x.d[0].v-v+a[t].d[1].v>=x.d[1].v){
					q[x.d[0].i].pop();
					q[x.d[0].i].push({i,x.d[0].v});
					q[a[t].d[1].i].push({t,a[t].d[1].v});
				}
				else{
					q[x.d[1].i].push({i,x.d[1].v});
				}
			}
		}
		while(q[0].size()) ans+=q[0].top().d,q[0].pop();
		while(q[1].size()) ans+=q[1].top().d,q[1].pop();
		while(q[2].size()) ans+=q[2].top().d,q[2].pop();
		cout<<ans<<'\n';
	} 
	return 0;
}
