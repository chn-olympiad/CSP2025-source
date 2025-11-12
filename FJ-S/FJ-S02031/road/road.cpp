#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+25,N=1e4+5;
int n,m,k,c[15],rp,f[N],ans;
bool b[15],rw[15],tj,ccnt[N];
vector<int> l[15];
struct line{
	int u,v,w,t;
	bool vis;
}a[M];
bool cmp(line a,line b){
	if(a.vis!=b.vis)return a.vis<b.vis;
	return a.w<b.w;
}
int find(int x){
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}
void add(int u,int v){
	u=find(u),v=find(v);
	f[u]=v;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		f[i]=i;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			a[++m]={n+i,j,w+c[i],i,0};
		}
	}
	while(rp<=n+k-1){
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;i++){
			if(a[i].vis||rp>n+k-1)break;
			a[i].vis=true;
			if(find(a[i].u)!=find(a[i].v)){
				rp++;
				ccnt[a[i].u]=1;
				ccnt[a[i].v]=1;
				add(a[i].u,a[i].v);
//				cout<<a[i].u<<" "<<a[i].v<<endl;
				ans+=a[i].w;
				if(a[i].t>0){
					l[a[i].t].push_back(a[i].w);
					if(!rw[a[i].u]){
						for(int j=1;j<=n+k;j++){
							if(a[j].t==a[i].t){
								a[j].w-=c[a[i].t];
							}
						}
						rw[a[i].u]=true;
						break;
					}	
				}
			}	
		}
		if(rp>n+k-1)break;
		tj=1;
		for(int i=1;i<=n;i++)tj=tj&&ccnt[i];
		if(tj)break;
	}
	for(int i=1;i<=k;i++){
		if(l[i].size()==1){
			ans-=c[i];
			ans-=l[i][0];
		}
	}
	cout<<ans;
}
