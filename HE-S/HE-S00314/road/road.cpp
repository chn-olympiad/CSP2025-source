#include <bits/stdc++.h>
#define int long long
using namespace std;
int father[11451];
int find(int x){
	if(father[x]!=x) father[x]=find(father[x]);
	return father[x];
}
void merge(int x, int y){
	x=find(x); y=find(y);
	if(x==y) return;
	father[x]=y; return;
} 
int n, m, k;
void init(int x){
	for(int i=1; i<=x; ++i){
		father[i]=i;
	}
}
struct Side{
	int u, v, w;
	bool operator <(const Side &o)const{
		return w<o.w; 
	}
}orig[2000500];
int a[11][11451];
int c[114514];
void Read(){
	cin>>n>>m>>k;
	for(int i=1; i<=m; ++i){
		int u, v, w;
		cin>>u>>v>>w;
		orig[i]={u,v,w};
	}
	//cout<<"Graph copmpleted\n";
	for(int j=1; j<=k; ++j){
		cin>>c[j];
		for(int i=1; i<=n; ++i){
			cin>>a[j][i];
		}
	}
}
vector <Side> tmp;
void Solve(){
	int ans=0x3f3f3f3f;
	for(int msk=0; msk<(1<<k); ++msk){
		int res=0, cnttt=n; tmp.clear();
		for(int i=1; i<=m; ++i){
			tmp.push_back(orig[i]);
		}
		for(int miao=1; miao<=k; ++miao){
			if(!(msk&(1<<(miao-1)))) continue;
			res+=c[miao]; ++cnttt;
			for(int i=1; i<=n; ++i){
				tmp.push_back({cnttt,i,a[miao][i]});
			}
		}
		init(cnttt);
		sort(tmp.begin(),tmp.end());
		for(int i=0; i<tmp.size(); ++i){
			Side now=tmp[i];
			int u=now.u, v=now.v, w=now.w;
			u=find(u), v=find(v);
			if(u==v) continue;
			merge(u,v); res+=w;
		}
		ans=min(ans,res); 
	}
	cout<<ans<<'\n';
	return;
}
void SolveA(){
	int ans=0;
	for(int i=1; i<=m; ++i) tmp.push_back(orig[i]);
	int cnttt=n;
	for(int miao=1; miao<=k; ++miao){
		++cnttt;
		for(int i=1; i<=n; ++i){
			tmp.push_back({cnttt,i,a[miao][i]});
		}
	}
	init(cnttt);
	sort(tmp.begin(),tmp.end());
	for(int i=0; i<tmp.size(); ++i){
		Side now=tmp[i];
		int u=now.u, v=now.v, w=now.w;
		u=find(u), v=find(v);
		if(u==v) continue;
		merge(u,v); ans+=w;
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	Read();
	if(k<=6&&m<=200000) Solve();
	else SolveA(); 
	return 0;
}
/*
56pts 求别挂

大梦一场的董二千先生

推开窗户 举起望远镜

眼底映出 一阵浓烟

前已无通路 后不见归途
*/
 
