#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4;
ll n,m,k,d[13],ans,p[N+20][2];
vector<pair<ll,pair<ll,ll>>> sv[N+15],v[N+15];
struct node{
	ll a,b,s;
}w[N*100+N*10+10];
void bfs(){
	queue<pair<ll,pair<ll,ll>>>q;
	for(int i=1;i<=n;i++) p[i][0]=LONG_LONG_MAX;
	q.push({1,{0,0}});
	while(q.size()){
		ll u=q.front().first,sum=q.front().second.first,d=q.front().second.second;
		q.pop();
		if(sum<=p[u][0]){
			p[u][0]=sum,p[u][1]=d;
		}
		else continue;
		for(auto h:sv[u]){
			ll tu=h.first,fs=h.second.first,pd=h.second.second;
			if(p[tu][0]>fs+p[u][0]){
				q.push({tu,{fs+p[u][0],pd}});
				p[tu][0]=fs+p[u][0];
			}
		}
	}
	ll pa[N+10],pb[N+10],pc[N+10];
	for(int i=2;i<=n;i++){
		ll ki=p[i][1];
		pa[i]=w[ki].a;pb[i]=w[ki].b,pc[i]=w[ki].s;
		ans+=w[ki].s;
	}
	for(int i=2;i<=n;i++){
		w[i-1].a=pa[i],w[i-1].b=pb[i],w[i-1].s=pc[i];
		v[w[i-1].a].push_back({w[i-1].b,{w[i-1].s,i-1}});
		v[w[i-1].b].push_back({w[i-1].a,{w[i-1].s,i-1}});
	}
}
ll bfs2(ll tp){
	queue<pair<ll,pair<ll,ll>>>q;
	ll cnt=0;
	for(int i=1;i<=n+k+1;i++) p[i][0]=0x3f3f3f3f3f3f3f3f,p[i][1]=0;
	q.push({1,{0,0}});
	while(q.size()){
		ll u=q.front().first,sum=q.front().second.first,d=q.front().second.second;
		q.pop();
		if(sum<=p[u][0]){
			p[u][0]=sum,p[u][1]=d;
		}
		else continue;
		for(auto h:v[u]){
			ll tu=h.first,fs=h.second.first,pd=h.second.second;
			if(p[tu][0]>fs){
				q.push({tu,{fs,pd}});
				p[tu][0]=fs;
			}
		}
	}
	for(int i=2;i<=n;i++){
		ll ki=p[i][1];
		cnt+=w[ki].s;
	}
	for(int i=1;i<=k;i++){
		if((tp>>(i-1))&1) cnt+=w[p[i+n][1]].s;
	}
	return cnt;
}
ll check(ll p){
	ll sum=0,u;
	for(int i=0;i<k;i++){
		ll mh=(p>>i)&1;
		if(mh==1){
			sum+=d[i+1];
			for(int j=1;j<=n;j++){
				u=(n-1)+i*n+j;
				v[i+n+1].push_back({j,{w[u].s,u}});
				v[j].push_back({i+n+1,{w[u].s,u}});
			}
		}
	}
	sum=sum+bfs2(p);
	for(int i=0;i<k;i++){
		ll mh=(p>>i)&1;
		if(mh==1){
			sum+=d[i+1];
			for(int j=1;j<=n;j++){
				v[i+n+1].pop_back();
				v[j].pop_back();
			}
		}
	}
	for(int i=1;i<=n;i++) cout<<v[i].size()<<" ";
	cout<<"\n";
	return sum;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>w[i].a>>w[i].b>>w[i].s;
		sv[w[i].a].push_back({w[i].b,{w[i].s,i}});
		sv[w[i].b].push_back({w[i].a,{w[i].s,i}});
	}bfs();
	ll len=n-1;
	for(int i=1;i<=n;i++) cout<<v[i].size()<<" ";
	cout<<"\n";
	for(int i=1;i<=k;i++){
		cin>>d[i];
		for(int j=1;j<=n;j++){
			ll hf;
			cin>>hf;
			++len;
			w[len].a=len,w[len].b=j,w[len].s=hf;
		}
	}
	for(int i=1;i<(1<<k);i++){
		ans=min(ans,check(i));
	}cout<<ans<<"\n";
	return 0;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
