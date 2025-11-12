#include<bits/stdc++.h>
using namespace std;
const int M=1e6+10,N=1e4+10;
int n,m,k,fa[N],c[15],b[15][N],s[N],ans;
struct node{
	int u,v,w;
}a[M];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(x!=fa[x]) return fa[x]=find(fa[x]);
	else return x;
}
void merge(int i,int j){
	int x=find(i),y=find(j);
	if(x!=y){
		if(s[x]>=s[y]){
			s[x]+=s[y];
			fa[y]=x;
		}else{
			s[y]+=s[x];
			fa[x]=y;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		s[i]=1;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	sort(a+1,a+1+m,cmp);
	if(k==0){
		for(int i=1;i<=m;i++){
			if(find(a[i].u)!=find(a[i].v)){
				merge(a[i].u,a[i].v);
				ans+=a[i].w;
			}
		}
	}
	cout<<ans<<endl;
}
