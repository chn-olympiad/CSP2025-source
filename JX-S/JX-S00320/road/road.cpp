#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
long long fa[N],ans,cnt=1;
int findx(int x){
	if(fa[x]!=x)return fa[x]=findx(fa[x]);
	else return fa[x];
}
long long n,m,k;
struct road{
	long long u,v,w;
}g[N];
bool cmp(road x,road y){
	return x.w<y.w;
}
void kk(){
	int sd=0;
	for(int i=1;i<=m+cnt;i++){
		if(sd==n-1){
			return;
		}
		if(findx(g[i].u)==findx(g[i].v)){
			continue;
		}else{
			ans+=g[i].w;
			fa[g[i].u]=findx(g[i].v);
			sd++;
		}
	}
}
int s[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>g[i].u>>g[i].v>>g[i].w;
	}
	for(int i=1;i<=k;i++){
		int p;
		cin>>p;
		for(int j=1;j<=n;j++){
			cin>>s[j];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				g[m+cnt].u=i,g[m+cnt].v=j,g[m+cnt].w=s[i]+s[j];
				cnt++;
			}
		}
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(g+1,g+1+m+cnt,cmp);
	kk();
	cout<<ans<<endl;
}
