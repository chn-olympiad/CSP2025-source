#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int fa[N];
int get(int x){
	if(fa[x]==x)return x;
	else return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	if(get(x)!=get(y)){
		fa[get(x)]=get(y);
	}
}
struct data{
	int begin,end,val;
};
bool cmp(data x,data y){
	return x.val<y.val;
}
vector<data> a;
int vis[N][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	if(!k){
		for(int i=1;i<=n;i++)fa[i]=i;
			for(int i=1;i<=m;i++){
				int u,v,w;
				cin>>u>>v>>w;
				a.push_back({u,v,w});
			}
		sort(a.begin(),a.end(),cmp);
		int ans=0;
		for(int i=0;i<m;i++){
			int x=a[i].begin,y=a[i].end;
			if(get(x)!=get(y)){
				ans+=a[i].val;
				merge(x,y);
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
