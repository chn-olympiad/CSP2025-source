#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int fa[10015];
int _find(int x){
	if(fa[x]==x)return x;
	return fa[x] = _find(fa[x]);
}
inline void join(int x,int y){
	if(_find(x)!=_find(y)){
		fa[_find(x)] = fa[y];
	}
}
struct road{
	int u,v,w;
};
inline bool cmp1(road& a,road& b){
	return a.w < b.w;
}
inline bool cmp2(road& a,road& b){
	return a.w > b.w;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector<road>r(m + 1);
	vector<long long>cbuilt(k + 1);
	vector<vector<long long> >ca(k + 1,vector<long long>(n + 1));
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		r[i] = {u,v,w};
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i = 1; i <= k;i++){
		cin>>cbuilt[i];
		for(int j = 1;j<=n;j++){
			int a;
			cin>>a;
			ca[i][j]=a;
		}
	}
	vector<road>sr(m+1);
	int cnt=0;
	sort(r.begin() + 1,r.begin() + m + 1, cmp1);
	long long sum=0;
	for(int i=1;i<=m;i++){
		int &u = r[i].u, &v = r[i].v;
		if(_find(u)!=_find(v)){
			join(u,v);
			sum += r[i].w;
			sr[cnt++]=r[i];
		}
	}
	sort(sr.begin(), sr.begin() + cnt, cmp2);
	for(road& tor:sr){
		int &u = tor.u, &v = tor.v, &w = tor.w;
		if(u==0)break;
		for(int j = 1;j <= k;j++){
			long long roun = cbuilt[j] + ca[j][u] + ca[j][v];
			if(roun <= w){
				cbuilt[j] = 0;
				sum-=w;
				sum+=roun;
				ca[j][u] = 0, ca[j][v] = 0;
				//cout<<"u:"<<u<<" v:"<<v<<" roun:"<<roun<<" x:"<<j<<'\n';
			}
		}
	}
	cout<<sum;
	return 0;
}
