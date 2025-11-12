#include<bits/stdc++.h>
using namespace std;
int fa[10005];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
bool insert(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return false;
	fa[x]=y;
	return true;
}
pair<int,pair<int,int> >ro[1000005];
int countryside[15][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>ro[i].second.first>>ro[i].second.second>>ro[i].first;
	} 
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>countryside[i][j];
		}
	}
	sort(ro+1,ro+1+m);
	int num=0,ans=0;
	for(int i=1;i<=m;i++){
		if(insert(ro[i].second.first,ro[i].second.second)){
			++num;
			ans+=ro[i].first;
			if(num>=n-1)break;
		}
	}
	cout<<ans;
	return 0;
}
