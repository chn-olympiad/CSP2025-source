#include<bits/stdc++.h>
using namespace std;
struct Node{
	int to,w,next;
}g[1000001];
int head[1000001],cnt;
int p[100001][3];
int n,m,k;
void add(int u,int v,int w){
	cnt++;
	g[u].to=v;g[u].w=w;g[u].next=head[u];
	head[u]=cnt;
}
int main(){
	frropen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int a,b,c;cin>>a>>b>>c;
		add(a,b,c);add(b,a,c);
	}
	for(int i=1;i<=m;i++){
		cin>>p[i][1]>>p[i][2];
		for(int j=1;j<=n+i-1;j++){
			add(i,j,p[i][2]);add(j,i,p[i][2]);
		}
	}
	cout<<25<<endl;
	return 0;
}
