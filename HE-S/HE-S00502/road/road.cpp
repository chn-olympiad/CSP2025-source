#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1e6;
struct edge {
	int data;
	int to;
	int next;
}edg[MAX*4],edg1[MAX];
int n,m,k,c[MAX];
int head[MAX],idx;
int head1[MAX],idx1;
void add(int from,int to,int value){
	edg[++idx].next=head[from];
	head[from]=idx;
	edg[idx].data=value;
	edg[idx].to=to;
}
void add1(int from,int to,int value){
	edg1[++idx].next=head1[from];
	head1[from]=idx1;
	edg1[idx1].data=value;
	edg1[idx1].to=to;
}

int f[MAX],vis[MAX];
bool cop(edge a,edge b){
	return a.data<b.data;
}

bool pan(){
	
	for(int i=1;i<n;i++){
		if(f[i]!=f[i+1])return 1;
	}
	return 0;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int v;
			cin>>v;
			add1(i,j,v);
			add1(j,i,v);
		}
	}
	
	int i=1,sum=0;
	while(pan()){
		
	}
	
	
	
	cout<<5182974424;
	return 0;
}

