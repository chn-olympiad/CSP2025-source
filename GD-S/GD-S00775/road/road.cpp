#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,x,y,z,fa[10025],fx,fy,ans,sum,tmp,c[15],aa[15][10025],ff=1;
struct St{
	int x,y,z;
};
vector<St> v,v2,vt; 
bool cmp(St A,St B){
	return A.z<B.z;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		v.push_back({x,y,z});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i])ff=0;
		for(int j=1;j<=n;j++){
			scanf("%lld",&aa[i][j]);
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=0;i<m;i++){
		fx=find(fa[v[i].x]);
		fy=find(fa[v[i].y]);
		if(fx!=fy){
			fa[fx]=fy;
			vt.push_back(v[i]);
			ans+=v[i].z;
		}
	}
	for(int tt=1;tt<(1<<k);tt++){
		sum=0;
		v2=vt;
		for(int i=0;i<k;i++){
			if((tt&(1<<i))!=0){
				sum+=c[i+1];
				for(int j=1;j<=n;j++){
					v2.push_back({n+i+1,j,aa[i+1][j]});
				}
			}
		}
		if(sum>=ans)continue;
		sort(v2.begin(),v2.end(),cmp);
		for(int i=1;i<=n+k;i++)fa[i]=i;
		for(int i=0;i<v2.size();i++){
			fx=find(fa[v2[i].x]);
			fy=find(fa[v2[i].y]);
			if(fx!=fy){
				fa[fx]=fy;
				sum+=v2[i].z;
				if(sum>=ans){
					sum=1e18;
					break;
				}
			}
		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}
