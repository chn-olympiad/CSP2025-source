#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct p{
	int r,w;
};
vector<p> f[10004];vector<int> h;
int a[10005][15],c[10005],v[10005],s;
bool cp(p x,p y){
	return x.w<y.w;
}

void cf(int x,int d){
	if(d==n) return;
	int ma=1e9,md=0;
	for(int i=0;i<h.size();i++){
		for(int j=0;j<f[h[i]].size();j++){
			if(v[f[h[i]][j].r]==0&&f[h[i]][j].w<ma){
				ma=f[h[i]][j].w;
				md=f[h[i]][j].r;
			}
		}
	}
//	cout<<md<<endl;
	v[md]=1;
	h.push_back(md);
	s+=ma;
	cf(x,d+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		f[x].push_back({y,w});
		f[y].push_back({x,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
//	sort(g+1,g+1+m,cp);
	v[1]=1;
	h.push_back(1);
	cf(1,1);
	cout<<s;
	return 0;
}
/*
4 4 0
1 3 2
1 2 4
1 4 5
2 4 1


*/
