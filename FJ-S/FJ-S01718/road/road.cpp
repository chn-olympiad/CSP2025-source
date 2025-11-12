#include<bits/stdc++.h>
using namespace std;
#define int long long
struct e{
	int x,y,z; 
}a[5000100];
bool cmp(e a,e b){
	return a.z<b.z;
}
int n,m,k,fa[1000100],c[1000100],w[11][100010];
int get(int x){
	if(x!=fa[x]) return x=get(fa[x]);
	return x;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>a[i].x>>a[i].y>>a[i].z;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>w[i][j];
		}
	}
	if(k==0){
		sort(a+1,a+n+1,cmp);
		int ans=0;
		for(int i=1;i<=m;i++){
			int x=a[i].x,y=a[i].y,z=a[i].z;
			if(get(x)!=get(y)){
				fa[get(x)]=get(y);
				ans+=z;
			}
		}
		cout<<ans;
	}
	int sum=0;
	for(int i=1;i<=k;i++) sum+=c[i];
	if(sum==0){
		int tot=m,po=n;
		for(int i=1;i<=k;i++){
			po++;
			for(int j=1;j<=n;j++) a[++tot].x=po,a[tot].z=w[i][j],a[tot].y=j;
		}
		for(int i=1;i<=po;i++) fa[i]=i;
		sort(a+1,a+tot+1,cmp);
		int ans=0;
		for(int i=1;i<=tot;i++){
			int x=a[i].x,y=a[i].y,z=a[i].z;
			if(get(x)!=get(y)){
				fa[get(x)]=get(y);
				ans+=z;
			}
		}
		cout<<ans;
	} 
} 
