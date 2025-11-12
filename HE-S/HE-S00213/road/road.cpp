#include<bits/stdc++.h>
using namespace std;
int n,m,k,len,fa[1110010];
bool flagag=false;
long long ans=0;
struct node{
	int u,v,w;
}a[1110010];
int find(int x){
	return fa[x]==x? x:fa[x]=find(fa[x]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		len++;
		scanf("%d%d%d",&a[len].u,&a[len].v,&a[len].w);
	}
	for(int i=1;i<=k;i++){
		bool flag=true;
		len++;
		scanf("%d",&a[len].w);
		cout<<a[len].w<<endl;
		if(a[len].w>0) flag=false;
		a[len].u=0; a[len].v=i+n;
		for(int j=1;j<=n;j++){
			len++;
			scanf("%d",&a[len].w);
			if(a[len].w>0) flag=false;
			a[len].u=i+n; a[len].v=j;
		}
		flagag=(flagag|flag);
	}
	if(flagag==true){
		cout<<0;
		exit(0);
	}
	for(int i=1;i<=n+k;i++) fa[i]=i;
	sort(a+1,a+1+len,cmp);
	for(int i=1;i<=len;i++){
		int p=find(a[i].u),q=find(a[i].v);
		if(p!=q){
			fa[p]=q;
			ans+=1ll*a[i].w;
			//cout<<a[i].u<<" "<<a[i].v<<"  "<<a[i].w<<endl;
		}
	}
	cout<<ans;
	return 0;
}
