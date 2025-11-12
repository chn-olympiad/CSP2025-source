#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N=10040,M=1000006;
int n,m,k,f[N],c[15],cnt,mi[15],mx[15],sx[15];
long long ans;
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
struct node{
	int u,v,w;
}b[M],d[11][N];
bool cmp(node aa,node bb){
	return aa.w<bb.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	mi[0]=1;
	for(int i=1;i<=13;i++)mi[i]=mi[i-1]*2;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>b[i].u>>b[i].v>>b[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>d[i][j].w;
			d[i][j].u=n+i,d[i][j].v=j;
		}
		sort(d[i]+1,d[i]+1+n,cmp);
//		for(int j=1;j<=n;j++){
//			cout<<d[i][j].u<<" "<<d[i][j].v<<" "<<d[i][j].w<<" !!!\n";
//		}
	}
	for(int i=1;i<=n;i++)f[i]=i;
	sort(b+1,b+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=b[i].u,y=b[i].v;
		x=find(x),y=find(y);
		if(x==y)continue;
		f[x]=y;
		d[0][++cnt]=b[i];
		ans=ans+b[i].w;
	}
	sx[0]=cnt;
	for(int i=1;i<=k;i++)sx[i]=n;
	for(int i=0;i<mi[k];i++){
		long long sum=0;
		for(int j=1;j<=k;j++){
			if(mi[j-1]&i){
				sum+=c[j];
			}
		}
		for(int j=1;j<=n+k;j++)f[j]=j;
		
		for(int i=0;i<=k;i++)mx[i]=1;
		for(int l=1;l<=n+k;l++){
			int x=0,y=0,w=1e9;
			for(int j=0;j<=k;j++){
				if(j==0||((mi[j]/2)&i)){
					while(mx[j]<=sx[j]){
						int xx=find(d[j][mx[j]].u),yy=find(d[j][mx[j]].v);
						if(xx==yy){
							mx[j]++;
						}else{
							int ww=d[j][mx[j]].w;
							if(ww<=w){
								w=ww,x=xx,y=yy;
							}
							break;
						}
					}	
				}
				
			}
			if(x!=0&&y!=0){
				sum+=w;
				f[x]=y;
			}
			if(sum>=ans)break;
		}
//		cout<<i<<" "<<sum<<" ???\n";
		ans=min(ans,sum);
	}
	cout<<ans<<"\n";
}
