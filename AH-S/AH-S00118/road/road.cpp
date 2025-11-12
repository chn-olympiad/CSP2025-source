#include<bits/stdc++.h>
using namespace std;
struct road{
	int st,en,w,r;
}a[10000005];
int c[15];
bool used[15];
int fa[10005];
int w[10005];
int n,m,k,l,cnt=0,ans=0;
bool cmp(road x,road y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void jxscs(){
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=l;i++){
		if(cnt==n-1) break;
		int tx=find(a[i].st),ty=find(a[i].en);
		if(tx!=ty){
			fa[ty]=tx;
			cnt++;
			ans+=a[i].w;
			if(used[a[i].r]==0){
				used[a[i].r]=1;
				ans+=c[a[i].r];
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	l=m;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].st,&a[i].en,&a[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&w[j]);
		}
		for(int j=1;j<=n;j++){
			for(int t=j+1;t<=n;t++){
				l++;
				a[l].st=j,a[l].en=t,a[l].w=w[j]+w[t],a[l].r=i;
			}
		}
	}
	sort(a+1,a+l+1,cmp);
	jxscs();
	cout<<ans<<endl;
}
