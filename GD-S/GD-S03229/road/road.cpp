#include<bits/stdc++.h>
#define int long long
using namespace std; 
void init(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
int n,m,k,sp,ans;
bool bj[11];
struct az{
	int la,lb,w,xc;
}edge[1000001];
map<int,bool> ma[1000001];
bool tp=0;
int xcc[11];
bool cmp(az x,az y){
	return x.w<y.w;
}
signed main(){
	init();
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,vv,ww;
		cin>>u>>vv>>ww;
		edge[++sp]={u,vv,ww,0};
	}
	for(int i=1,c;i<=k;i++){
		cin>>xcc[i];
		if(xcc[i]){
			tp=1;
		}
		int a[n+1];
		for(int j=1;j<=n;j++){
			cin>>a[j];
			if(a[j]){
				tp=1;
			}
			for(int k=1;k<j;k++){
				edge[++sp]={j,k,a[j]+a[k]+xcc[i],i};
			}
		}
	}
	if(!tp){
		cout<<0;
		return 0;
	}
	sort(edge+1,edge+sp+1,cmp);
	if(!k){
		for(int i=1;i<=n-1;i++){
			ans+=edge[i].w;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n-1;i++){
		if(!ma[edge[i].la][edge[i].lb]){
			ans+=edge[i].w;
			ma[edge[i].la][edge[i].lb]=1;
			if(edge[i].xc){
				if(bj[edge[i].xc]){
					ans-=xcc[edge[i].xc];
				}
				else{
					bj[edge[i].xc]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
