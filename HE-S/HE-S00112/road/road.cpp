#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+19,M=2e6+19;
int n,m,k;
struct edge{
	int x;
	int y;
	int w;
}a[M];
int fa[N],c[13][N],flag[15],cnt;
ll ans;
ll find(int x){
	if(fa[x]==x)return fa[x];
	else return fa[x]=find(fa[x]);
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i][1];
		for(int j=1;j<=n;j++){
			cin>>c[i][j+1];
		}
	}
	
	if(k==0){
		sort(a+1,a+m+1,cmp);
		int cnt=0;
		for(int i=1;i<=m;i++){
			int xx=find(a[i].x);
			int yy=find(a[i].y);
			if(xx!=yy){
				fa[xx]=yy;
				ans+=a[i].w;
				cnt++;
				if(cnt>=n-1)break;
			}
		}
		cout<<ans<<"\n";
	}
	else {
		sort(a+1,a+m+1,cmp);
		cnt=0;
		for(int i=1;i<=m;i++){
			int xx=find(a[i].x);
			int yy=find(a[i].y);
			if(xx!=yy){
				fa[xx]=yy;
				ans+=a[i].w;
				cnt++;
				if(cnt>=n-1)break;
			}
		}
		//cout<<ans<<"\n";
		
		for(int l=1;l<=k;l++){
			ll anst=c[l][1];
			for(int i=1;i<=n+1;i++)fa[i]=i;
			for(int i=1;i<=n;i++){
				a[i+m].x=n+1;
				a[i+m].y=i;
				a[i+m].w=c[l][i+1];
			}
			sort(a+1,a+m+n+1,cmp);
			cnt=0;
			for(int i=1;i<=n+m;i++){
				int xx=find(a[i].x);
				int yy=find(a[i].y);
				if(xx!=yy){
					fa[xx]=yy;
					anst+=a[i].w;
					cnt++;
					if(cnt>=n)break;
				}
			}
			if(anst<ans)flag[l]=1;
		}
		//for(int i=1;i<=n+1;i++)fa[i]=i;
		int cntt=0;
		ll anss=0;
		for(int i=1;i<=k;i++){
			if(flag[i]){
				anss+=c[i][1];
				for(int j=1;j<=n;j++){
					a[m+j+n*cntt].x=n+1+cntt;
					a[m+j+n*cntt].y=i;
					a[m+j+n*cntt].w=c[i][j+1];
					
				}
				cntt++;
			}
		}
		//cout<<cntt<<" ";
		sort(a+1,a+m+cntt*n+1,cmp);
		cnt=0;
		for(int i=1;i<=n+cntt;i++){
			fa[i]=i;
			
		}
		
		for(int i=1;i<=n*cntt+m;i++){
			int xx=find(a[i].x);
			int yy=find(a[i].y);
			//cout<<fa[yy]<<" ";
			if(xx!=yy){
				fa[xx]=yy;
				//cout<<i<<"\n";
				anss+=a[i].w;
				//if(anss==7)cout<<a[i].y<<"\n";
				//cout<<anss<<"\n";
				cnt++;
				if(cnt>=n+cntt-1)break;
			}
		}
		cout<<anss<<"\n";
	}
	return 0;
} 
