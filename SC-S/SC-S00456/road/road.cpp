#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10005],ans,cnt,b[15][10005];
pair<int,pair<int,int> >a[600005];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void kus(){
	for(int i=1;i<=cnt;i++){
		int v=a[i].second.second,u=a[i].second.first;
		if(find(u)!=find(v)){
			ans+=a[i].first;
			fa[u]=v;
		}
	}
	cout<<ans;
	exit(0);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i].second.first>>a[i].second.second>>a[i].first;
	}
	cnt=m;
	sort(a+1,a+1+cnt);
	if(k==0){
		kus();
	}
	for(int i=1;i<=k;i++){
		cin>>b[i][0];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int l=j+1;l<=n;l++){
				a[++cnt]={b[k][l]+b[k][j]+b[i][0],{j,l}};
			}
		}
	}
	kus();
	return 0;
}