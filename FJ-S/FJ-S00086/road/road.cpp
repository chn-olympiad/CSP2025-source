#include<bits/stdc++.h>
using namespace std;
vector <int>a[100005];
long long n,m,k,v[1000005],b[100000005],c[1000005];
long long ans=1000000000005;
void za(long long x,long long y,long long z){
	if(y>ans){
		return ;
	}
	if(z>=n){
		bool b=1;
		for(int i=1;i<=n;i++){
			if(v[i]==0){
				b=0;
			}
		}
		if(b==1){
			ans=min(ans,y);
			return ;
		}
	}
	for(int i=0;i<a[x].size();i++){
		if(v[a[x][i]]==0){
			if(a[x][i]>n){
				v[a[x][i]]=1;
				za(a[x][i],y+b[x*a[x][i]]+c[a[x][i]],z+1);
				v[a[x][i]]=0;
			}else{
				v[a[x][i]]=1;
				za(a[x][i],y+b[x*a[x][i]],z+1);
				v[a[x][i]]=0;
			}
		}
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		b[u*v]=w;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i+n];
		for(int j=1;j<=n;j++){
			cin>>b[(i+n)*j];
			a[i+n].push_back(j);
			a[j].push_back(i+n);
		}
	}
	za(1,0,1);
	cout<<ans;
	return 0;
}
