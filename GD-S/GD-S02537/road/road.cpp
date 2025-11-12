#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,m,k;
struct node{
	int x,y,z;
}g[8000100];
int g2[15][20005],sy[15];
int t,d[15],fa[20005];
inline bool cmd(node a,node b){
	int aa=a.z,bb=b.z;
	for(int i=1;i<=k;i++)
		if(sy[i])
			aa=min(aa,g2[i][a.x]+g2[i][a.y]),bb=min(bb,g2[i][b.x]+g2[i][b.y]);
	return aa<bb;
}
inline void add(int x,int y,int z){
	g[++t].x=x;
	g[t].y=y;
	g[t].z=z;
}
inline int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int sum;
bool aaaaaaaaa=true;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("road3.in","r",stdin); 
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%lld %lld %lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) add(i,j,ULONG_LONG_MAX);
	for(int i=1;i<=k;i++){
		int x;
		cin>>d[i];
		for(int j=1;j<=n;j++){
			cin>>x;
			g2[i][j]=x;
			if(x!=0) aaaaaaaaa=false;
		}
	}
//	sort(g+1,g+1+t,cmd);
//	int sss=0;
//	for(int i=1;i<=t&&sss<n-1;i++){
//		int x=g[i].x,y=g[i].y;
//		int xx=find(x),yy=find(y);
//		if(xx!=yy){
//			fa[xx]=yy;
//			sum+=g[i].z;
//			sss++;
//		}
//	}
//		cout<<1;
	if(aaaaaaaaa){
		int ans=ULONG_LONG_MAX;
		for(int i=1;i<=k;i++) ans=min(ans,d[i]);
		cout<<ans;
		return 0;
	}
	int sss,sum=ULONG_LONG_MAX;
	for(int ii=0;ii<=k;ii++){
		sss=0;
		int ssum=d[ii],tt=0;
		for(int i=1;i<=n;i++) fa[i]=i;
		sy[ii]=1;
		sort(g+1,g+1+t,cmd);
//		for(int i=1;i<=t+k*n;i++) cout<<g[i].x<<" "<<g[i].y<<" "<<g[i].z;
		for(int i=1;i<=t&&sss<n-1;i++){
			int x=g[i].x,y=g[i].y;
			int xx=find(x),yy=find(y);
			if(xx!=yy){
				fa[xx]=yy;
				int aa=g[i].z;
				for(int j=1;j<=k;j++)
					if(sy[j])
						aa=min(aa,g2[j][x]+g2[j][y]);
				ssum+=aa;
//				cout<<x<<" "<<y<<" "<<aa<<"\n";
				sss++;
//				cout<<g[i].z<<" "<<g[i].x<<" "<<g[i].y<<"\n";
			}
		}
//		cout<<"\n";
		if(ssum<=sum) sum=ssum;
		else sy[ii]=0;
	}
	cout<<sum;
}
