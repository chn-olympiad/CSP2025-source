#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,u,v,w,c[15],d[15][10025],fa[10025],ans,tim;
bool flag=1;
struct node{
	int u,v,w;
}a[2000005],b[2000005];
bool cmp(node x,node y){
	return x.w<y.w;
}
int zx(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=zx(fa[x]);
}
signed main()
{
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[i]={u,v,w};
//		b[i]=a[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0){
			flag=0;
		}
		for(int j=1;j<=n;j++){
			cin>>d[i][j];
			if(d[i][j]!=0){
				flag=0;
			}
		}
	}
	if(flag){
		cout<<0;
		return 0;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int x=a[i].u,y=a[i].v;
		if(zx(x)==zx(y)){
			continue;
		}
		ans+=a[i].w;
		fa[zx(x)]=zx(y);
		b[++tim]={x,y,a[i].w};
	}
	if(k==0){
		cout<<ans;
		return 0;
	}
	for(int s=0;s<(1<<k);s++){
		int tot=n-1,res=0;
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
		}
		for(int i=1;i<n;i++){
			a[i]=b[i];
		}
		for(int i=0;i<k;i++){
			if(s&(1<<i)){
				res+=c[i+1];
				for(int j=1;j<=n;j++){
					a[++tot]={n+i+1,j,d[i+1][j]};
				}
			}
		}
		sort(a+1,a+tot+1,cmp);
		for(int i=1;i<=tot;i++){
			int x=a[i].u,y=a[i].v;
			if(zx(x)==zx(y)){
				continue;
			}
			res+=a[i].w;
			fa[zx(x)]=zx(y);
//			cout<<x<<" "<<y<<" "<<a[i].w<<"\n";
		}
		if(res<ans){
			ans=res;
		}
//		cout<<res<<"\n";
	}
	cout<<ans;
	return 0;
}


