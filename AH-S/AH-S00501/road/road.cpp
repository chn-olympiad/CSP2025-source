#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,M=1e4+5;
struct node{
	int from,to,val;
}a[10*N],b[N*10];
int f[N],c[M][M],n,m,k,tot,ans=LONG_LONG_MAX;
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
bool cmp(node a,node b){
	return a.val<b.val;
}
int kruskal(){
	int cnt=0,ans=0;
	for(int i=1;i<=tot;i++) b[i]=a[i];
	sort(a+1,a+tot+1,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=tot&&cnt<n-1;i++){
		//cout<<a[i].from<<" "<<f[a[i].from]<<endl;
		int t1=find(a[i].from),t2=find(a[i].to);
		if(t1!=t2){
			ans+=a[i].val;
			cnt++;
			f[t1]=t2;
		}
	}
	for(int i=1;i<=tot;i++) a[i]=b[i];
	return ans;
}
void dfs(int idx,int h){
	if(idx==k+1){
		ans=min(ans,h+kruskal());
		return ;
	}
	dfs(idx+1,h);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			a[++tot]={i,j,c[idx][i]+c[idx][j]};
		}
	}
	dfs(idx+1,h+c[idx][0]);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			tot--;
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	bool fa=1;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[++tot]={x,y,z};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		if(c[i][0]!=0) fa=0;
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	if(fa){
		for(int l=1;l<=k;l++){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					a[++tot]={i,j,c[l][i]+c[l][j]};
				}
			}
		}
		cout<<kruskal()<<endl;
		return 0;
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
