#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair

int n,m,k;
struct Node{
	int u,v,w;
}a[1101];
int ans=0;
int f[1101];
int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}

bool cmp(Node q,Node p){
	return q.w<p.w;
}

void solve1(){
	for(int i=1;i<=n;i++) f[i]=i;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		int fx=find(a[i].u),fy=find(a[i].v);
		if(fx==fy) continue;
		else{
			f[fx]=fy;
			ans+=a[i].w;
		}
	}
	cout<<ans;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
//	if(k==0){
		solve1();
//	}
//	else{
		for(int i=1;i<=k;i++){
			int x;
			cin>>x;
			for(int i=1;i<=n;i++){
				cin>>x;
			}
		}
//	}
	
	
	return 0;
}
/*
4 4 0 
1 4 6 
2 3 7 
4 2 5 
4 3 4 


*/ 
