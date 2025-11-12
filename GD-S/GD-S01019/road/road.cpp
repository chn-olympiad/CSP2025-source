#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=1e4+10;
struct node{
	int x,y,z;
}a[N*2],b[N*2];
int c[20][M];
bool operator<(node num,node num2){
	return num.z<num2.z;
}
int n,m,k,fa[N*2];
bool vis[20];
long long minn=1e18;
inline int find(int x){
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	else return x;
}
inline void kruskal(){
	long long sum=0,cnt=0;
	for(int i=1;i<=k;i++) if(vis[i]) sum+=c[i][0];
	if(sum>minn) return;
	int newn=n,newm=m;
	for(int i=1;i<=m;i++) a[i].x=b[i].x,a[i].y=b[i].y,a[i].z=b[i].z;
	for(int i=1;i<=k;i++){
		if(vis[i]){
			newn++;
			for(int j=1;j<=n;j++){
				a[++newm].x=j,a[newm].y=newn,a[newm].z=c[i][j];
			}
		}
	} 
	for(int i=1;i<=newn;i++) fa[i]=i;
	sort(a+1,a+newm+1);
	for(int i=1;i<=newm;i++){
		int fx=find(a[i].x),fy=find(a[i].y);
		if(fx!=fy){
			fa[fx]=fy;
			sum+=a[i].z;
			cnt++;
			if(sum>minn) return;
			//cout<<cnt<<" "<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
			if(cnt==newn-1) break;
		}
	}
	if(cnt!=newn-1) return; 
	minn=min(minn,sum);
//	cout<<sum<<" "<<minn<<endl;
//	for(int i=1;i<=k;i++) cout<<vis[i]<<" ";
//	cout<<endl;
}
inline void mc(int x){
	if(x==k+1){
		kruskal();
		return;
	}
	mc(x+1);
	vis[x]=1;
	mc(x+1);
	vis[x]=0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		b[i].x=a[i].x,b[i].y=a[i].y,b[i].z=a[i].z;
	} 
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
		}
	}
	mc(1);
	cout<<minn<<endl;
	return 0;
}
