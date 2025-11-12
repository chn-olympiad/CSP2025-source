#include<bits/stdc++.h>
using namespace std;
//#define int long long
struct edge{
	int u,v,w;
};
int s[10035];
edge e[1000005];
int a[15][10005];
int c[15];
vector<edge> vc;
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int fid(int x){
	if(s[x]!=x) s[x]=fid(s[x]);
	return s[x];
}
int main(){
	int n,m,k;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		s[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(e+1,e+m+1,cmp);
	int tmp=0;
	for(int i=1;i<=m;i++){
		if(fid(e[i].u)!=fid(e[i].v)){
			s[fid(e[i].u)]=fid(e[i].v);
			e[i-tmp]=e[i];
		}
		else{
			tmp++;
		}
	}
	m-=tmp;
//	for(int i=1;i<=m;i++) cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<"NOS\n";
	long long ans=1e18,cn,res;
	for(int i=0;i<(1<<k);i++){
		vc.clear();
		cn=n;
		res=0;
		
		for(int j=0;(1<<j)<=i;j++){
			if((i>>j)&1){
				int v=j+1;
				cn++;
				res+=c[v];
				for(int z=1;z<=n;z++){
					vc.push_back({cn,z,a[j+1][z]});
				}
			}
		}
		
		sort(vc.begin(),vc.end(),cmp);
 
		for(int i=1;i<=cn;i++) s[i]=i;
		int l=1,ll=0,siz=cn;
		
		while(ll<vc.size()||l<=m){
			if(siz==1) break;
			if(l<=m&&(ll>=(int)vc.size()||e[l].w<=vc[ll].w)){
				if(fid(e[l].u)!=fid(e[l].v)){
					s[fid(e[l].u)]=fid(e[l].v);
					res+=e[l].w;
					siz--;
				}
				l++;
			}
			else{
				if(fid(vc[ll].u)!=fid(vc[ll].v)){
					s[fid(vc[ll].u)]=fid(vc[ll].v);
					res+=vc[ll].w;
					siz--;
				}
				ll++;
			}
			
		}
		ans=min(ans,res);
	}
	cout<<ans;
	
	
	return 0;
}
