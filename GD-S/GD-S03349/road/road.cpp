#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[20010],yk[10010][20],p[110],cnt,s;
bool v[110];
struct node{
	int u,v,w;
};
node a[1000010];
long long ans;
bool cmp(node x1,node x2){
	return x1.w<x2.w;
}
int find(int x){
	if(f[x]!=x) x=find(f[x]);
	return f[x];
} 
int main(){	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++){
    	cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=k;i++){
		cin>>p[i];
		for(int j=1,w;j<=n;j++){
			cin>>yk[j][i];
		}
	}
	while(cnt!=n-1){
		s++;
		int x=a[s].u,y=a[s].v;
		int fx=find(x),fy=find(y);
		if(fx==fy) continue;
		int mi=a[s].w,id=0;
		for(int i=1;i<=k;i++){
			long long h=yk[fx][i]+yk[fy][i];
			if(!v[i]) h+=p[i];
			if(h<=mi){
				id=i;
				mi=h;
			}
		}
		ans+=mi;
		f[fx]=fy;
		for(int i=1;i<=k;i++) yk[fy][i]=min(yk[fy][i],yk[fx][i]);
		yk[fy][id]=0;
		v[id]=true;
		cnt++;
	}
	cout<<ans;
	return 0;
}
