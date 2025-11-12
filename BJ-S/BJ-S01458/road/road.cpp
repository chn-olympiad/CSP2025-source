#include<bits/stdc++.h>
#define N 20004
#define int long long
#define pb push_back
#define mk make_pair
using namespace std;
int n,m,k,uu,vv,ww,c,aa,minu,minv,minw,cnt=0,cnt1=0;
int tim[N],sum[N],ans=0;
struct edge{
	int u,v,w;
	edge(int u1,int v1,int w1):u(u1),v(v1),w(w1){}
	bool operator <(const edge &x)const{
		return w>x.w;
	}
};
vector<pair<int,int> >nxt[N];
priority_queue<edge>q;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	minw=1e10;
	for(int i=1;i<=m;i++){
		cin>>uu>>vv>>ww;
		nxt[uu].pb(mk(vv,ww));
		nxt[vv].pb(mk(uu,ww));
		if(ww<minw){
			minw=ww;minu=uu;minv=vv;
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>aa;
			nxt[n+i].pb(mk(j,aa));
			nxt[j].pb(mk(n+i,aa));
			if(aa<minw){
				minw=aa;minu=j;minv=n+i;
			}
		}
	}
	q.push(edge(minu,minv,minw));
	while(!q.empty()){
//		cnt1++;
		edge tmp=q.top();q.pop();
		if(tim[tmp.u]>0&&tim[tmp.v]>0)continue;
		if(tim[tmp.u]==0&&tmp.u<=n)cnt++;
		if(tim[tmp.v]==0&&tmp.v<=n)cnt++;
//		cout<<tmp.u<<' '<<tmp.v<<' '<<tmp.w<<'\n';
		tim[tmp.v]++;tim[tmp.u]++;
		ans+=tmp.w;sum[tmp.u]+=tmp.w;sum[tmp.v]+=tmp.w;
		if(cnt==n)break;
		if(tim[tmp.u]==1){
			for(pair<int,int>to:nxt[tmp.u]){
				if(tim[to.first]==0)q.push(edge(tmp.u,to.first,to.second));
			}
		}
		if(tim[tmp.v]==1){
			for(pair<int,int>to:nxt[tmp.v]){
				if(tim[to.first]==0)q.push(edge(tmp.v,to.first,to.second));
			}
		}
	}
	for(int i=1;i<=k;i++){
		if(tim[i]==0)ans-=sum[i];
	}
	cout<<ans;
//	cout<<'\n'<<cnt1;
	return 0;
}
