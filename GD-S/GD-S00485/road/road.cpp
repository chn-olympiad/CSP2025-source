#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e6+10;
struct node{
	int u,v,va;
};
node e[N];
int n,m,k,cnt;
int p[N];
int c[N];
int e_ne[1010][1010];
int edge_j[20][N];
int find(int x){
	if(p[x]!=x) find(p[x]);
	return p[x];
}
bool cmp(node A,node B){
	return A.va<B.va;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c; 
		e[++cnt].u=a,e[cnt].v=b,e[cnt].va=c;
		e[++cnt].u=b,e[cnt].v=a,e[cnt].va=c;
	}
	bool flag=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];if(c[i]!=0) flag=false;
		for(int j=1;j<=n;j++){
			cin>>edge_j[i][j];
		}
	}
	if(k==0){
		int ans=0;
	//	cout<<cnt<<endl;
		sort(e+1,e+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){
			int kx=e[i].u,ky=e[i].v;
			int px=find(kx),py=find(ky);
			if(px!=py){
				p[px]=py;
				ans+=e[i].va;
			}
		}
		cout<<ans<<endl;
		return 0;
	}else if(flag){
		if(n<=1e3+10){
			
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					e_ne[i][j]=0x3f3f3f3f;
				}
			}
			for(int i=1;i<=k;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=1;k<=n;k++){
						for(int h=1;h<=n;h++){
							e_ne[k][h]=min(e_ne[k][h],(edge_j[i][k]+edge_j[j][h]));
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
//					if(e_ne[i][j]==0){
//						p[i]=j;
//					}else{
						e[++cnt].u=i,e[cnt].v=j,e[cnt].va=e_ne[i][j];
						e[++cnt].u=j,e[cnt].v=i,e[cnt].va=e_ne[j][i];
				//	}
					
				}
			}
			int ans=0;
	//	cout<<cnt<<endl;
		sort(e+1,e+cnt+1,cmp);
//		for(int i=1;i<=cnt;i++){
//			cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].va<<endl;
//		}
		for(int i=1;i<=cnt;i++){
			int kx=e[i].u,ky=e[i].v;
			
			//cout<<p[3]<<" "<<p[2]<<endl;
			int px=find(kx),py=find(ky);
		//	cout<<px<<" "<<py<<endl;
			if(px!=py){
				p[py]=px;
				ans+=e[i].va;
			}
		}
		cout<<ans<<endl;
		return 0;
		}
	}
	return 0;
} 
