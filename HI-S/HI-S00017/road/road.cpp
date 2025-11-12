#include<bits/stdc++.h> 

using namespace std;

int n,m,k;
int u,v,w;

int a[10010];
int weight[10010];

int f_fa(int k){
	if(a[k]==k){
		return k;
	}else{
		a[k]=f_fa(a[k]);
		return a[k];
	}
}

bool check(int u,int v){
	if(f_fa(u)!=f_fa(v)){
		return false;
	}else{
		return true;
	}
}

void gt(int u,int v){
	int u1=f_fa(u);
	int v1=f_fa(v);
	if(weight[u1]<weight[v1]){
		swap(u1,v1);
	}
	a[v1]=u1;
}

struct edge{
	int u,v,w;
	bool operator<(const edge e)const{
		if(w<e.w){
			return true;
		}else{
			return false;
		}
	}
};

edge map1[100005];
int cost=0;
int en=0; 

void mst(){
	for(int i=0;i<m;i++){
		int u1=map1[i].u;
		int v1=map1[i].v;
		int w1=map1[i].w;
		if(check(u1,v1)){
			continue;
		}
		cost+=w1;
		en++;
		if(en==n-1){
			return;
		}
		gt(u1,v1);
	}
}


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<10010;i++){
		a[i]=i;
	}
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		map1[i]={u,v,w};
	}
	sort(map1,map1+m);
	mst();
	cout<<cost;
	return 0;
}

