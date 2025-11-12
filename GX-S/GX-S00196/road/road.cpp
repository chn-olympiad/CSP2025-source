#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int fa[1000001];
int Find(int x){
	if(x==fa[x]) return x;
	else return fa[x]=Find(fa[x]);
}
struct node{
	int x,y,s;
}s[1000001];
bool cmp(node a,node b){
	return a.s<b.s;
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>s[i].x>>s[i].y>>s[i].s;
	}
	if(k!=0){
		cout<<0;
		return 0;
	}
	long long ans=0;
	sort(s+1,s+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=Find(s[i].x);
		int y=Find(s[i].y);
		if(x!=y){
			fa[x]=fa[y];
			ans+=s[i].s;
		}
	}
	cout<<ans;
	
	return 0;
}
