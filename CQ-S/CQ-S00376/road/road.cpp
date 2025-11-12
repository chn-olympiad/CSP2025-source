#include<bits/stdc++.h>

using namespace std;
const int N=2e6+7;
int n,m,k,f[N],ans,c[N];
struct node{
	int u,v,w;
}a[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1 ; i <= n+k ; i++){
		f[i]=i;
	}
	for(int i = 1 ; i <= m ; i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	if(k==0){
		sort(a+1,a+m+1,cmp);
		for(int i = 1 ; i <= m ; i++){
			if(find(a[i].u)!=find(a[i].v)){
				f[find(a[i].u)]=f[find(a[i].v)];
				ans+=a[i].w;
			}
		}
		cout<<ans;
	}
	else{
		for(int i = 1 ; i <= k ; i++){
			cin>>c[i];
			for(int j = 1 ; j <= n ; j++){
				a[++m].u=j;
				a[m].v=n+i;
				cin>>a[m].w;
				if(a[m].w==0){
					f[find(a[m].u)]=f[find(a[m].v)];
					m--;
				}
			}
		}
		sort(a+1,a+m+1,cmp);
		for(int i = 1 ; i <= m ; i++){
			if(find(a[i].u)!=find(a[i].v)){
				f[find(a[i].u)]=f[find(a[i].v)];
				ans+=a[i].w;
			}
		}
		cout<<ans;
	}
	return 0;
} 

