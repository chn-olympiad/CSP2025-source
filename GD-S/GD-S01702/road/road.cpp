#include<bits/stdc++.h>
using namespace std;
struct e{
	int u,v,w,p;
}g[1100005];
bool v[15];
int a[10005],f[10005],h[15],n,m,k,ans;
bool cmp(e a,e b){
	return a.w+h[a.p]<b.w+h[b.p];
}
int fd(int x){
	if(x==f[x]) return x;
	return f[x]=fd(f[x]);
}
void mg(int x,int y){
	f[fd(x)]=fd(y); 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>g[i].u>>g[i].v>>g[i].w;
		g[i].p=-1;
	}
	for(int j=0;j<k;j++){
		cin>>h[j];
		for(int i=1;i<=n;i++){
			int y;
			cin>>y;
			g[m+j*n+i-1].u=n+j+1;
			g[m+j*n+i-1].v=i;
			g[m+j*n+i-1].w=y;
			g[m+j*n+i-1].p=j;
		}
	}
	int m_=m+k*n;
	sort(g,g+m_,cmp);
	for(int i=1;i<=n+k;i++){
		f[i]=i;
	}
	for(int i=0;i<m_;i++){
//		cout<<g[i].u<<' '<<g[i].v<<' '<<g[i].w<<' '<<g[i].p<<' ';
//		bool f=0;
		if(fd(g[i].u)!=fd(g[i].v)){
			mg(g[i].u,g[i].v);
			if(g[i].p!=-1){
				if(v[g[i].p]==0){
					v[g[i].p]=1;
					ans+=h[g[i].p];
					h[g[i].p]=0;
					sort(g,g+m_,cmp);
				}
			}
			ans+=g[i].w;
//			f=1;
		}
		bool s=0;
		for(int i=2;i<=n;i++){
			if(fd(1)!=fd(i)){
				s=1;
				break;
			}
		}
		if(s==0) break;
//		if(f) cout<<"y\n";
//		else cout<<"n\n";
	}
	cout<<ans;
	return 0;
}

