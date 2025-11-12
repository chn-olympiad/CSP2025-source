#include<bits/stdc++.h>
using namespace std;
struct item{
	int u,v;
	long long k;
}a[1100000];
int n,m,k;
int fa[1100000];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
bool cmp(item x,item y){return x.k<y.k;}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].u>>a[i].v>>a[i].k;
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	if(k==0){
		sort(a+1,a+n+1,cmp);
		long long ans=0;
		for(int i=1;i<=n;i++){
			int xx=find(a[i].u),yy=find(a[i].v);
			if(xx!=yy){
				fa[xx]=yy;
				ans+=a[i].k;
			}
		}
		cout<<ans;
	}else{
		cout<<0;
	}
	return 0;
} 
