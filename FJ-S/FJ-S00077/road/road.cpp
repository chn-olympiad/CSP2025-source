#include<bits/stdc++.h>
using namespace std;
const int N=1e4+4;
int n,m,k,c[15],cnt,f[N];
long long ans=0;
bool flag;
int a[15][N];
struct node{
	int u,v,w;
	bool operator<(const node &t){
		return w<t.w;
	} 
}r[11000004];
vector<node>e;
int fnd(int h){
	if(f[h]==h){
		return h;
	}
	return f[h]=fnd(f[h]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
	flag=1; 
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]){
			flag=0;
		}
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(!k){
		for(int i=1;i<=n;i++){
			f[i]=i;
		} 
		sort(r+1,r+m+1);
		for(int i=1;i<=m;i++){
			int xx=fnd(r[i].u),yy=fnd(r[i].v);
			if(xx==yy){
				continue;
			}
			ans+=r[i].w;
			cnt++;
			f[xx]=yy;
			if(cnt==n-1){
				break;
			}
		}
		cout<<ans;
	}
	if(flag){
		for(int i=1;i<=k;i++){
			for(int j=1;j<n;j++){
				for(int g=j+1;g<=n;g++){
					r[++m].u=j,r[m].v=g,r[m].w=a[i][j]+a[i][g];
				}
			} 
		}
		for(int i=1;i<=n;i++){
			f[i]=i;
		} 
		sort(r+1,r+m+1);
		for(int i=1;i<=m;i++){
			int xx=fnd(r[i].u),yy=fnd(r[i].v);
			if(xx==yy){
				continue;
			}
			ans+=r[i].w;
			cnt++;
			f[xx]=yy;
			if(cnt==n-1){
				break;
			}
		}
		cout<<ans;
	}
	return 0;
}
