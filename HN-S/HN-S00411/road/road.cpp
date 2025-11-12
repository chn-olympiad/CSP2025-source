#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+50,maxm=1.2e6+5,maxk=10;
struct aaa{
	int x,y,w;
	bool op;
}b[maxm];
int n,m,k,cnt,w[maxk+5];
long long ans[1<<maxk],mini=1e18;
bool cmp(aaa x,aaa y){
	return x.w<y.w;
}
int fa[1<<maxk][maxn];
int find(int x,int op){
	if(fa[op][x]==x){
		return x;
	}
	return fa[op][x]=find(fa[op][x],op);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	cnt=m;
	for(int i=1;i<=m;i++){
		cin>>b[i].x>>b[i].y>>b[i].w;
		b[i].op=1;
	} 
	for(int i=1;i<=k;i++){
		cin>>w[i];
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			b[++cnt]={n+i,j,x,0}; 
		} 
	}
	for(int j=0;j<(1<<k);j++){
		for(int ff=1;ff<=k;ff++){
			if((j>>(ff-1))&1){
				ans[j]+=w[ff];
			}
		}
	} 
	for(int i=1;i<=n+k;i++){
		for(int j=0;j<(1<<k);j++){
			fa[j][i]=i;
		} 
	}
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
//		cout<<i<<" "<<b[i].x<<" "<<b[i].y<<" "<<b[i].w<<" "<<b[i].op<<"___________\n";
		if(find(b[i].x,0)!=find(b[i].y,0)){
			if(b[i].op){
				for(int j=0;j<(1<<k);j++){
					int fx=find(b[i].x,j),fy=find(b[i].y,j);
					if(fx!=fy){
						fa[j][fy]=fx;
						ans[j]+=b[i].w;
					}
				}
			}
			else{
				for(int j=0;j<(1<<k);j++){
					if((j>>(b[i].x-n-1))&1){
						int fx=find(b[i].x,j),fy=find(b[i].y,j);
						if(fx!=fy){
							fa[j][fy]=fx;
							ans[j]+=b[i].w;
						}
					} 
				} 
			}
		} 
	}
	for(int j=0;j<(1<<k);j++){
		mini=min(mini,ans[j]);
	}
	cout<<mini;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
