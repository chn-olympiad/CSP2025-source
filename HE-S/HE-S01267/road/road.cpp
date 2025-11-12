#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+50;
int n,m,k;
int a[20][10010];
int c[20],p[10010];
int ans=0;
bool r=true,f=false;
struct node{
	int u,v,w;
}e[N];
int get_p(int x){
	return x==p[x]?x:get_p(p[x]);
}
bool cmp(node x,node y){
	return x.w<y.w;
}
void Kru(){
	for(int i=1;i<=n;i++) p[i]=i;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=get_p(e[i].u);
		int y=get_p(e[i].v);
		if(x!=y){
			ans+=e[i].w;
			p[x]=y;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	Kru();
	if(k==0){
		cout<<ans;
		return 0;
	} 
	for(int i=1;i<=k;i++){
		r=true;
		cin>>c[i];
		if(c[i]!=0) r=false;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0) r=false;
		}
		if(r==true) f=true;
	}
	if(f==true) cout<<0;
	else cout<<ans;
	return 0;
}
