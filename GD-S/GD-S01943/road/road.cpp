#include<bits/stdc++.h>
using namespace std;
int jie[15],cnt=0,fa[1015],ans=0;
vector<int> g[1005]; 
struct naa{
	int from,to,val,v;

}b[2035];
bool cmp(naa s,naa x){
	return s.val<x.val;
}
int found(int a){
	if(fa[a]==a) return a;
	return fa[a]=found(fa[a]);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,z;
		cin>>u>>v>>z;
		b[i].from=u;
		b[i].to=v;
		b[i].val=z;
	}
	int cnt1=1;
	for(int j=1;j<=k;j++){
		int v1;
		cin>>v1;
		for(int i=1;i<=n;i++){
			int z;
			cin>>z;
			b[m+cnt1].from=i;
			b[m+cnt1].to=n+j;
			b[m+cnt1].val=z+v1;
			b[m+cnt1].v=v1;
			cnt1++;
		}
	}

	sort(b+1,b+m+n*k+1,cmp);
	for(int i=1;i<m+n*k;i++){
		if(found(b[i].from)!=found(b[i].to) && cnt<n+k){
			fa[found(b[i].from)]=found(b[i].to);
			found(b[i].from);

			cnt++;
			if(b[i].to>n && jie[b[i].to-n]!=0){
				jie[b[i].to-n]++;
				g[b[i].to-n].push_back(i);
				ans+=b[i].val-b[i].v;
			}else if(jie[b[i].to-n]==0  && b[i].to>n){
				jie[b[i].to-n]++;
				g[b[i].to-n].push_back(i);
				ans+=b[i].val;
							
			}else{
				ans+=b[i].val;			
			}

		}
	}
	for(int i=1;i<=k;i++){
		if(jie[i]==1){
			for(auto u:g[i]){
				ans-=b[u].val;
			}
		}
	}
	cout<<ans;
	return 0;
} 
