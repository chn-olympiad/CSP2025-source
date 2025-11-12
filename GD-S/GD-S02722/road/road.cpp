#include<bits/stdc++.h>
#define TIMU (string)"road"
#define ll long long
#define ull unsigned long long
using namespace std;
struct _bcj{
	int fa[1000005];
	int hb_cnt = 0;
	void init(int n =1000003){
		for(register int i = 0;i<n;i++) fa[i] = i;
	}
	int get_jhnum(int x){
		/*int r = fa[x]==x ? x : get_jhnum(x);
		fa[x] = r;
		printf("get_jhnum x=%d res=%d\n",x,r);*/
		int r = x;
		while(fa[r]!=r){
			r = fa[r];
		}
		fa[x] = r;
		return r;
	}
	void he_bin(int a,int b){
		//if(a>b) swap(a,b);
		int af = get_jhnum(a),bf = get_jhnum(b);
		if(af!=bf) hb_cnt++;
		fa[max(af,bf)] = min(af,bf);
		//printf("he_bin %d %d hb_cnt=%d\n",a,b,hb_cnt);
	}
};
struct edge{
	int u,v,w;
};
_bcj bcj;
int n,m,k;
vector<edge> e;
int c[114];
bool is_tj(){
	int x = bcj.get_jhnum(0);
	for(int i = 1;i<n;i++) if(bcj.get_jhnum(i)!=x) return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen((TIMU+".in").c_str(),"r",stdin);freopen((TIMU+".out").c_str(),"w",stdout);
	cin>>n>>m>>k;
	bcj.init(123456);
	for(int i = 0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({u-1,v-1,w});
		//e.push_back({v,u,w});
	}
	for(int i = 0;i<k;i++){
		cin>>c[i];
		for(int j = 0;j<m;j++){
			int u=n+i,v=j,w;
			cin>>w;
			e.push_back({v,u,w});
			//e.push_back({u,v,w});
		}
	}
	sort(e.begin(),e.end(),[&](edge a,edge b){
		return a.w<b.w;
	});
	/*for(edge i : e){
		cout<<"edge u="<<i.u<<" v="<<i.v<<" w="<<i.w<<endl;
	}*/
	int cnt = 0,cos = 0;
	while(!is_tj()){//bcj.hb_cnt<-1+n){
		edge t = e[cnt];cnt++;
		//cout<<"tmp edge u="<<t.u<<" v="<<t.v<<" w="<<t.w<<" | cnt="<<cnt<<endl;
		if(bcj.get_jhnum(t.u)!=bcj.get_jhnum(t.v)){
			bcj.he_bin(t.u,t.v);
			cos+=t.w;
		}
	}
	cout<<cos;
	return 0;
}

