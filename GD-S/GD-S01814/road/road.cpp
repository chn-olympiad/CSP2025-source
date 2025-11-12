#include<bits/stdc++.h>
using namespace std;
int a[10010];
int n,m,k;long long cnt=0;
bool pt,cp;
int bcj(int k){
	if(a[k]==k)return k;
	return bcj(a[k]);
}
struct st{
	int u,v;long long w;
}road[1000010];
bool cmp(st i,st j){
	return i.w<j.w;
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)a[i]=i;
	for(int i=1;i<=m;i++){
		cin>>road[i].u>>road[i].v>>road[i].w;
	}
	for(int i=1;i<=k;i++){
		int ch;
		cin>>ch;if(ch!=0)pt=true;
		for(int j=1;j<=n;j++){
			cin>>ch;if(ch!=0)cp=true;
		}
	}
	sort(road+1,road+1+m,cmp);
	for(int i=1;i<=m;i++){
		a[road[i].u]=bcj(road[i].u);
		a[road[i].v]=bcj(road[i].v);
		if(a[road[i].u]!=a[road[i].v]){
			cnt+=road[i].w;
			a[road[i].u]=a[road[i].v];
		}
	}
	if(pt==false&&cp!=true&&k!=0)cout<<"0";
	else cout<<cnt;
	return 0;
}
