#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[15],a[15][10005],vis[1000044],f[100005];long long ans;
struct node{
	int u,v,w;
}ex[1000005],ae[15][10005],ed[300005],eu[300005],eh[300005];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		ex[i]={u,v,w};
	}sort(ex+1,ex+m+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			ae[i][j]={i+n,j,a[i][j]};
		}
		sort(ae[i]+1,ae[i]+n+1,cmp);
	}
	for(int i=1;i<=n;i++)f[i]=i;
	int cnt=0,len;
	for(int i=1,fx,fy;i<=m;i++){
		fx=find(ex[i].u);fy=find(ex[i].v);
		if(fx!=fy){
			cnt++;
			f[fx]=fy;
			ed[cnt]=ex[i];
			ans+=ex[i].w;
		}
	}
//	cout<<ans<<"\n";
	for(int i=0;i<(1<<k);i++){
		len=cnt;long long cc=0,ss=0;
		for(int j=1;j<=cnt;j++)eh[j]=ed[j];
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				ss+=c[j];
				for(int c=1;c<=len;c++)eu[c]=eh[c];
				int o=1,oo=1;
				for(int c=1;c<=len+n;c++){
					if(o==len+1||(eu[o].w>ae[j][oo].w&&oo!=n+1)){
						eh[c]=ae[j][oo];
						oo++;
					}
					else{
						eh[c]=eu[o];o++;
					}
				}
				len+=n;
			}
		}
		for(int i=1;i<=k+n;i++)f[i]=i;
//		cout<<len<<"\n";
		for(int j=1,fx,fy;j<=len;j++){
			fx=find(eh[j].u);fy=find(eh[j].v);
			if(fx!=fy){
				cc++;
				f[fx]=fy;
				ss+=eh[j].w;
//				cout<<eh[j].w<<" "<<"\n";
			}
		}
//		cout<<i<<" "<<ss<<"\n";
		ans=min(ans,ss);
		if(ans==0){
			break;
		}
	}cout<<ans<<"\n";
	return 0;
}
