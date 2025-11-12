#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define st first
#define nd second
const int N=2e4+5,M=2e6+5;
vector<pii>e[N],e3[N];
struct Edge{
	int u,v,w;
	bool operator<(Edge t){
		return w<t.w;
	}
}e2[M];
int n,m,k,c[15],a[15][N],fa[N],cnt1;
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int fun(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(e2+1,e2+cnt1+1);
	ll ans=0,cnt=1;
	for(int tt=1;tt<=cnt1;tt++){
		Edge t=e2[tt];
		if(t.u==0&&t.v==0&&t.w==0)continue;
		//cout<<t.u<<' '<<t.v<<' '<<t.w<<endl;
		if(find(t.v)!=find(t.u)){
			fa[t.v]=t.u;
			ans+=t.w;
			cnt++;
		}if(cnt>=n){
			return ans;
		}
	}return INT_MAX;
}void fun2(int tt,ll &ans,int more){
	if(more>ans)return;
	if(tt==k){
		cnt1=0;
		for(int i=1;i<=n;i++){
			for(auto j:e[i]){
				//for(auto k:e[i][j]){
					e2[++cnt1]={i,j.st,j.nd};
				//}
				//
			}
			//
		}
		for(int i=1;i<=cnt1;i++){
			auto tttt=e2[i];
			cout<<tttt.u<<' '<<tttt.v<<' '<<tttt.w<<endl;
		}
		ll ttt=fun()+more;cout<<ttt<<' '<<ans<<endl;
		ans=min(ans,ttt);
		
		return;
	}
	fun2(tt+1,ans,more);
	int u=tt;
	e[u].clear();
	for(int i=1;i<=n;i++){
		if(i==tt)continue;
		e[u].push_back({i,a[u][i]});
		int k=0;
		for(auto j:e[i]){
			if(j.st==u){
				e[i][k].nd=a[u][i];
			}k++;
		}
	}fun2(tt+1,ans,more+c[tt]);
	for(int i=1;i<=n;i++)e[i]=e3[i];
}
void solve(){
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
		e3[u].push_back({v,w});
		e3[v].push_back({u,w});
		e2[++cnt1]={u,v,w};
		e2[++cnt1]={v,u,w};
		//cout<<"!!!!"<<u<<' '<<v<<' '<<w<<endl;
	}for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
		}
	}ll ans=fun();
	//fun2(0,ans,0);
	cout<<ans<<'\n';
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	solve();
	cout<<flush;
	fclose(stdin);fclose(stdout); 
	return 0;
} 
