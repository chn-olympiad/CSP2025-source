#include<bits/stdc++.h>
using namespace std;
struct h{
	int u;
	int v;
	int w;
};
int n;//城市
int m;//道路 
int k;//乡镇
int cnt;
int ans;
int net[1000010];
int head[10010]; 
h load[1000010];
void add(int a,int b,int c){
	cnt++;
	load[cnt].u=a;
	load[cnt].v=b;
	load[cnt].w=c;
	net[cnt]=head[a];
	head[a]=cnt;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
cin>>n>>m>>k;
for(int i=1;i<=m;i++){
	int x,y,z;
	cin>>x>>y>>z;
}
int c[1000010];
for(int i=1;i<=k;i++){
	cin>>c[i];
	int s[n+1];
for(int l=1;l<=n;l++){
cin>>s[l];
ans=min(s[l],ans);
}
}cout<<ans;
	return 0;
}
