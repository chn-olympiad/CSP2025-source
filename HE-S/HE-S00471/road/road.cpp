#include<bits/stdc++.h>
#define int unsigned long long 
const int N=1e6+100;
const long long M=2e7+100;
using namespace std;
int p[N];
int find(int x){
	if(p[x]!=x){
		return find(p[x]);
	}
	return x;
}
int s[N];
int n,m,k;
struct Edge {
	int u;
	int v;
	int w;
}a[M];
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int c;
int cnt=0;
int ans=0;
int sum=0;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<=n;i++){
		p[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[i].u=u;
		a[i].v=v;
		a[i].w=w;
	}
	cnt=m;
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>s[j];
		}	
		for(int j=1;j<=n;j++){
			for(int kk=j+1;kk<=n;kk++){
				if(j!=kk){
					cnt++;
					a[cnt].u=j;
					a[cnt].v=kk;
					a[cnt].w=c+s[j]+s[kk];
				}
			//	cnt++;
			}
		}
	}
	
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(sum==n-1){
			break;
		}
		int x=find(a[i].u);
		int y=find(a[i].v);
		if(x!=y){
			p[x]=y;
			sum++;
			ans+=a[i].w;
		}
	}
	cout<<ans;
	return 0;
}
