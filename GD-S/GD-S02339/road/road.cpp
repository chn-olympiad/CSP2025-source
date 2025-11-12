#include<bits/stdc++.h>
using namespace std;
int n,m,k,tp=m;
struct node{
	int u,v,w;
}e[10000005];
int f[10000005],c[1000005];
map<int,int>mp;
int find(int x){
	if(f[x]==x){
		return x;
	}
	return x=f[x]=find(f[x]);
}
void merge(int x,int y){
	f[find(x)]=find(y);
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			tp++;
			cin>>e[tp].w;
			e[tp].u=i+n,e[tp].v=j;
		}
	}
	for(int i=1;i<=tp;i++){
		f[i]=i;
	}
	long long sum=n,ans=0;
	sort(e+1,e+tp+1,cmp);
	int i=0;
	while(sum!=1){
		i++;
		if(find(e[i].u)!=find(e[i].v)){
			merge(e[i].u,e[i].v);
			sum--;
			if(mp[e[i].u]==1&&e[i].u>n){
				ans+=c[e[i].u-n];
			}
			mp[e[i].u]++;
			ans+=e[i].w;
		}
	}
	cout<<ans;
	return 0;
}
