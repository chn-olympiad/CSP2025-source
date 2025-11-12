#include<bits/stdc++.h>
using namespace std;
const int M=1000005;

struct P{
	int u,v,w;
};
P e[M];
int f[M];
int a[M];
int find(int x){
	return f[x]==x?x:find(f[x]);
}

void mem(int a,int b){
	a=find(a);b=find(b);
	f[a]=b;
}
/*
int pu(int u,int v,int w){
	e[u].push_back((P){v,w});
	e[v].push_back((P){u,w});
}*/

bool cmp(P x,P y){
	return x.w<y.w;
}


int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	int n,m,k;
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	
	for(int i=1;i<=m;i++){
		int v;int u;int w;cin>>v>>u>>w;
		e[i]=((P){u,v,w});
	}
	
	///////////////////////
	for(int i=1;i<=k;i++){
		memset(a,0,sizeof(a));
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		
	}

	///////////////////////////
    sort(e+1,e+n+1,cmp);
    long long sum=0;
    for(int i=1;i<=m;i++){
    	if(!(find(e[i].u)==find(e[i].v))){
    		sum+=e[i].w;
    		mem(e[i].u,e[i].v);
		}
	}
    cout<<sum<<endl;

	return 0;
}
