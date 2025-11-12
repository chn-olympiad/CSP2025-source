#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	int n,m,k,d=0,money=0,now;
	int u[10000],v[10000],w[10000],c[12],a[12][10000];
	cin>>n>>m>>k;
	bool r[n];
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++){
			r[n]=false;
			cin>>a[i][j];
		}
	}
	for(int i=0;i<m;i++){
		d=min(w[i],d);
	}
	for(int i=0;i<m;i++){
		if(d==w[i]){
			r[u[i]]=true;
			r[v[i]]=true;
			money+=w[i];
			now=i;
			break;
		}
	}
	for(int i=0;i<m;i++){
		if(u[now]==u[i]&&now!=i&&!r[v[i]]&&w[i]<=(c[i]+a[i][v[i]]+a[i][u[i]])){
			r[v[i]]=true;
			money+=w[i];
		}
		if(v[now]==v[i]&&now!=i&&!r[u[i]]){
			r[u[i]]=true;
			money+=w[i];
		}
	}
	cout<<money;
	return 0;
} 
