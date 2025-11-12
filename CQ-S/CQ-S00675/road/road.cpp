#include<bits/stdc++.h>
using namespace std;
int n,m,k,p[15],f[10015],zz[100015],ccb[20005],vis[15];
int find(int x){return x==f[x] ? x : f[x]=find(f[x]);}
void me(int x,int y){
	int a=find(x),b=find(y);
	if(a==b) return;
	if(zz[a]<zz[b]) f[a]=b;
	else if(zz[a]>zz[b]) f[b]=a;
	else f[a]=b,zz[b]++;
} 
struct node{
	int u,v,w,yyy;
	friend operator<(node x,node y){
		return x.w<y.w;
	}
};
vector<node> v;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		v.push_back({x,y,z,0});
	}
	bool ff=1;
	for(int i=1;i<=k;++i){
		scanf("%d",&p[i]);
		if(p[i]!=0) ff=0;
		int id=0;	
		for(int j=1;j<=n;++j){
			scanf("%d",&ccb[i]);
			if(ccb[j]==0) id=j;
		}
		if(id==0 || p[i]!=0){
			for(int j=1;j<=n;++j){
				for(int k=j+1;k<=n;++k){
					v.push_back({j,k,ccb[j]+ccb[k],i});
				}
			}
		}
		else{
			for(int j=1;j<=n;++j){
				if(j==id) continue;
				v.push_back({id,j,ccb[j],0});
			}
		}
	}
	long long ans=0x3f3f3f3f3f3f3f3f,re=0,used=0;
	sort(v.begin(),v.end());
	if(ff){
		for(int i=1;i<=n+10;++i) f[i]=i,zz[i]=1;
		for(node t:v){
			int x=t.u,y=t.v,w=t.w;
			if(find(x)!=find(y)){
				me(x,y);
				re+=w;
				++used;
				if(used==n-1) break;
			}
		}
		cout<<re;
		return 0;
	}
	for(int tmp=0;tmp<(1<<k);tmp++){
		long long res=0;
		for(int i=1;i<=n+10;++i) f[i]=i,zz[i]=1;
		memset(vis,0,sizeof vis);
		for(node t:v){
			int x=t.u,y=t.v,w=t.w;
			if(find(x)!=find(y) && (t.yyy==0 || (0>>(t.yyy-1))&1)){
				me(x,y);
				if(vis[t.yyy]==0 && t.yyy!=0) res+=p[t.yyy],vis[t.yyy]=1;
				res+=w;
				++used;
				if(used==n-1) break;
			}
		}
		ans=min(res,ans);
	}
	
	cout<<ans;
	return 0;
}

