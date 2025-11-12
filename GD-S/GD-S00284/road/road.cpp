#include<bits/stdc++.h>
using namespace std;
const int M=1e4+15;
const long long N=1e10;
struct rd{
	int v;
	long long w;
};
vector<rd> mp[M];//i点到v点权值w 
queue<int> q;
int n,m,k;
int n_n;
int fa[M];
int ans;
int get(int i){
	if(fa[i]==i) return i;
	else return fa[i]=get(fa[i]);
}
void merge(int a,int b){
	if(fa[get(a)]==get(b)) return;
	fa[get(a)]=get(b);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		mp[u].push_back({v,w});
		mp[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		long long asd[n+5];
		cin >> asd[0];
		for(int j=1;j<=n;i++){
			cin >> asd[j];
		}
		for(int j=1;j<=n;j++){
			for(int z=1;z!=i && z<=n;z++){
				mp[j][z].w=mp[z][j].w=min(mp[j][z].w,asd[j]+asd[z]);
			}
		}
	}
	q.push(1);
	int cnt=0;
	while(cnt!=n){
		int qf=q.front();
		long long minn=N;
		int minv;
		for(int i=0;i<mp[qf].size();i++){
			int v=mp[qf][i].v,w=mp[qf][i].w;
			if(fa[get(qf)]==get(v)) continue;
			else{
				if(minn>w){
					minn=w;
					minv=v;
				}
			}
		}
		q.push(minv);
		ans+=minn;
		cnt++;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
}
