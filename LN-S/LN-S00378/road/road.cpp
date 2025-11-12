#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
int f[N];
int ans=0;
struct road{
	int p1,p2,w;
}a[M+10*N];
struct country{
	int c;
	int b[N];
	int fa;
}cc[11];
int n,m,k;
bool cmpp(road x,road y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]==x) return x;
	return find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>a[i].p1>>a[i].p2>>a[i].w;
	} 
	for(int i=1;i<=k;i++){
		cin>>cc[i].c;
		vector<int> g;
		for(int j=1;j<=n;j++){
			cin>>cc[i].b[j];
			if(cc[i].b[j]==0) g.push_back(j);
		}
		for(int i=1;i<g.size();i++){
			f[g[i]]=find(g[0]);
		}
		cc[i].fa=g[0];
	}
	if(k==0){
		sort(a+1,a+1+m,cmpp);
		for(int i=1;i<=m;i++){
			if(find(a[i].p1)==find(a[i].p2)) continue;
			ans+=a[i].w;
			f[a[i].p1]=find(a[i].p2);
		}
		cout<<ans<<endl;
		return 0;
	}
	int mm=m;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(!cc[i].b[j]) continue;
			a[++mm].p1=cc[i].fa;
			a[mm].p2=j;
			a[mm].w=cc[i].b[j];
		}
	}
	ans=0;
	sort(a+1,a+mm+1,cmpp);
	for(int i=1;i<=mm;i++){
		if(find(a[i].p1)==find(a[i].p2)) continue;
		ans+=a[i].w;
		f[a[i].p2]=find(a[i].p1);
	}
	cout<<ans<<endl;
	return 0;
}
