#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
};
bool cmp(node a,node b){
	return a.w>b.w;
}
vector<node>vec;
int f[10010];
void init(){
	for(int i=0;i<10010;i++){
		f[i]=i;
	}
	return;
}
int get(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=get(f[x]);
}
void merge(int x,int y){
	x=get(x);
	y=get(y);
	if(x!=y){
		f[x]=y;
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	int n,m,k;
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		vec.push_back({u,v,w});
	}
	int c;
	int a[10010];
	int s[n+1][n+1];
	memset(s,0x3f,sizeof(s));
	for(int i=0;i<k;i++){
		cin>>c;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(c==0)s[i][j]=min(s[i][j],a[i]+a[j]);
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			vec.push_back({i,j,s[i][j]});
		}
	}
	sort(vec.begin(),vec.end(),cmp);
	int ans=0;
	for(int i=vec.size()-1;i>=0;i--){
		if(get(vec[i].u)!=get(vec[i].v)){
			ans+=vec[i].w;
			merge(vec[i].u,vec[i].v);
		}
	}
	cout<<ans;
	return 0;
}
