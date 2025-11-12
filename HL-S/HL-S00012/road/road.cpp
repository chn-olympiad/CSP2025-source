//hajimi o nan bei lu duo.
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Edge{
	int fr,to,val;
	bool operator< (Edge ano) const {
		return val>ano.val;
	};
};
priority_queue<Edge> Q,q;
int a[11][11000],v[11],fa[11000],res[11000];
int getfa(int x){
	if(fa[x]==x) return x;
	return fa[x]=getfa(fa[x]);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,K,ans=0x3f3f3f3f3f3f3f3f;cin>>n>>m>>K;
	for(int i=1;i<=m;i++){
		int x,y,val;cin>>x>>y>>val;
		Q.push({x,y,val});
	}
	bool isA=true;
	for(int i=1;i<=K;i++){
		cin>>v[i];if(v[i]!=0) isA=false;
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(isA){
		int t=n,ans=0,cnt=0;q=Q;
		for(int i=1;i<=K;i++){
			t++;
			for(int j=1;j<=n;j++) q.push({t,j,a[i][j]});
		}
		for(int i=1;i<=t;i++) fa[i]=i;
		while(not q.empty()){
			Edge now=q.top();q.pop();
			int x=now.fr,y=now.to;
			if(getfa(x)==getfa(y)) continue;
			fa[getfa(x)]=getfa(y);ans+=now.val;cnt++;
			if(cnt==t-1) break;
		}
		cout<<ans<<'\n';
		return 0;
	}
	for(int S=0;S<=(1<<K)-1;S++){
		bool fl=false;
		for(int s=0;s<=(1<<K)-1;s++){
			if((S&s)==s and (res[s]<0)){
				//cout<<s<<" ..... ";
				fl=true;
				break;
			}
		}
		if(fl) continue;
		int t=n,cnt=0;q=Q;
		for(int i=1;i<=K;i++){
			if(((S>>(i-1))&1)){
				res[S]+=v[i];t++;
				for(int j=1;j<=n;j++) q.push({t,j,a[i][j]});
			}
		}
		for(int i=1;i<=t;i++) fa[i]=i;
		while(not q.empty()){
			Edge now=q.top();q.pop();
			int x=now.fr,y=now.to;
			if(getfa(x)==getfa(y)) continue;
			fa[getfa(x)]=getfa(y);res[S]+=now.val;cnt++;
			if(cnt==t-1) break;
		}
		//cout<<S<<" "<<fl<<" "<<res[S]<<'\n';
		ans=min(ans,res[S]);
		for(int s=0;s<=(1<<K)-1;s++){
			if((S&s)==s and S!=s){
				if(res[S]>=res[s]){
					res[S]=-1;
					break;
				}
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
//Wo shi chang zhui yi guo qu...
//Wo gai zai na li ting liu ,wo wen wo zi ji.