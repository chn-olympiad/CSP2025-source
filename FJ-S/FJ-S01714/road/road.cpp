#include<bits/stdc++.h>
using namespace std;
long long fa[10005],n,m,k,top,ans,ww[10005],p;
long long find(long long x){
	if(fa[x]==x){
		return x;
	}
	fa[x]=find(fa[x]);
}
void merge(int x,int y){
	find(x);
	find(y);
	fa[x]=fa[y];
	find(x);
	find(y);
}
struct node{
	int u,v,w;
}a[10000050];
bool cmp(node x,node y){return x.w<y.w;}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	p=n;
	top=m;
	for(int i=1;i<=m;i++){cin>>a[i].u>>a[i].v>>a[i].w;}
	for(int i=1;i<=k;i++){
		int c,q;
		cin>>c;
		for(int j=1;j<=n;j++){cin>>ww[i];}
		for(int j=1;j<=n;j++){
			for(int k=1;k<j;k++){
				top++;
				a[top].u=k;
				a[top].v=j;
				a[top].w=ww[j]+ww[k];
			}
		}
	}
	sort(a+1,a+1+top,cmp);
	for(int i=1;i<=n;i++){fa[i]=i;}
	for(int i=1;i<=top&&p>1;i++){
		int u=a[i].u,v=a[i].v;
		find(u);
		find(v);
		if(fa[u]!=fa[v]){
			ans+=a[i].w;
			merge(u,v);
			p--;
		}
	}
	cout<<ans;
}
