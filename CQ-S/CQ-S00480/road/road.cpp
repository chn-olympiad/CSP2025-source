#include <bits/stdc++.h>
using namespace std;

struct Node{
	int u,v,w,f;
};

int n,m,k;

int a[200000];

Node arr[1000010];

int t[10][20000];

vector <Node> mp; 

int fa[200000];

int vis[100];

bool cmp(Node T,Node S){
	return T.w<S.w;
}

int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}

bool until(int f,int s){
//	cout<<1;
	int fx = find(f);
	int fy = find(s);
	if(fx == fy) return 0;
	fa[fx] = fy;
	return 1;
}

int Prim(){
	int w=0;
	int r=0;
//	cout<<1;
	for(int i=0;i<mp.size();i++){
		Node temp = mp[i];
		if(until(temp.u,temp.v)){
			w+=temp.w;
//			cout<<temp.u<<" "<<temp.v<<" "<<temp.w<<endl;
			if(vis[temp.f]==1){
				vis[temp.f]=1;
				w-=t[temp.f][0];
			}
			r++;
		}
		if(r==n-1){
			break; 
		}
	}
	return w;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&arr[i].u,&arr[i].v,&arr[i].w);
		arr[i].f=0;
	}
	
	for(int i=1;i<=n;i++) fa[i] = i;
	
	for(int l=1;l<=k;l++){
		for(int i=0;i<=n;i++){
			scanf("%d",&t[l][i]);
		}
	} 
	sort(arr+1,arr+1+n,cmp); 
	for(int i=1;i<=m;i++) mp.push_back({arr[i].u,arr[i].v,arr[i].w,arr[i].f});
//	cout<<1;
	
	if(k!=0){
		int ans=0x3f3f3f3f;
		for(int i=1;i<=k;i++){
			ans = min(ans,t[i][0]);
		}
		cout<<min(ans,Prim());
	}
	else{
		cout<<Prim();
	}
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
