#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int m[10005][10005],a,b,c,u,v,w,n,k[11][10005],cv[10005],o;
vector<int>g;
int t=100009;
int search(int l,int h,int q){
	if(l==0){
		g.push_back(q);
		return 0;
	}
	int y=q;
	for(int i=1;i<=a;i++){
		if(m[h][i]!=-1){
			o=m[h][i];
			q+=o;
			m[h][i]=-1;
			m[i][h]=-1;
			search(l-1,i,q);
			m[h][i]=o;
			m[i][h]=o;
			q=y;
		}
	}
	return 0;
}
int main(){
	g.clear();
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	cin>>a>>b>>c;
	for(int i=1;i<=a;i++){
		for(int j=1;j<=a;j++){
			m[i][j]=-1;
		}
	}
	for(int i=1;i<=b;i++){
		cin>>u>>v>>w;
		m[u][v]=w;
		m[v][u]=w;
	}
	for(int i=1;i<=c;i++){
		cin>>n;
		for(int j=1;j<=a;j++){
			cin>>k[i][j];
		}
	}
	search(a-1,1,0);
	for(int i=0;i<a;i++){
		if(g[i]>=0){
			t=min(t,g[i]);
		}
	}
	cout<<t;
	freopen("road.ans","w",stdout);
}

