#include<bits/stdc++.h>
using namespace std;
int gg[10005],n,m,k,c[10005],b[100][100],total,sum;
struct p{
	int u;
	int v;
	int w;
}a[1000005];
int g(int x){
	if(gg[x]!=x) return g(gg[x]);
	return gg[x];
}
bool cmp(p ll,p rr){
	return ll.w<rr.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int q=1;q<=n;q++){
			
			gg[q]=q;
			
	}
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		
		for(int q=1;q<=n;q++){
			a[m+(i-1)*n+q].u=i;a[m+(i-1)*n+q].v=q;cin>>a[m+(i-1)*n+q].w;
		}
		
		
	}
	sort(a+1,a+m+k*n+1,cmp);
	for(int i=1;i<=m+k*n;i++){
		
		if(g(a[i].u)!=g(a[i].v)){
			
			total+=a[i].w;
			gg[a[i].u]=g(a[i].v);
			sum++;
		}
	
		if(sum==n-1) {
		
		cout<<total;break;}
	}
	return 0;
}
