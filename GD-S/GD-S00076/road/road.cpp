#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e4+10;
const int M=1e6+10;

int n,m,k;
int ans=0;

struct ed{
	int u,v,w;
}e[M];

bool cmp(ed x,ed y){
	return x.w>y.w;
}

signed main(){
	//16·Ö 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=n;i++){
			int u,v,w;
			cin>>u>>v>>w;
			ans+=w;
		}
		cout<<ans;
		
		return 0;
	}else{
		for(int i=1;i<=m;i++){
			cin>>e[i].u>>e[i].v>>e[i].w;
		}
		sort(e+1,e+n+1,cmp);
		for(int i=k+1;i<=m;i++){
			ans+=e[i].w;
		}
		cout<<ans;
		return 0;
	}
	
	return 0;
}
