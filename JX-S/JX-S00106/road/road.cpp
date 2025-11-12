#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int fi[10100];
int vil[20][10100];
//int h[100100];
int f(int i){
	if(fi[i]==i) return i;
	fi[i]=f(fi[i]);
	return fi[i];
	}
struct edge{
	int u,v,w;
	}e[200010];
bool cmp(edge x,edge y){
	return x.w<y.w;
	}
void t0(){
	for(int i=1;i<=m;i++){
	cin>>e[i].u>>e[i].v>>e[i].w;
	}
/*for(int i=1;i<=k;i++){
	for(int i=1;i<=n;i++){
		cin>>e[m+i].w;
		e[m+i].u=0;
		e[m+i].v=i;
		}
	}*/
for(int i=1;i<=n;i++)
	fi[i]=i;
sort(e+1,e+m+1,cmp);
for(int i=1;i<=m;i++){
	int fx=f(e[i].u),fy=f(e[i].v);
	if(fx==fy) continue;
	fi[fx]=fy;
	ans+=e[i].w;
	}
cout<<ans;
	}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
cin>>n>>m>>k;
if(k==0){
	t0();
	return 0;
	}
for(int i=1;i<=m;i++){
	cin>>e[i].u>>e[i].v>>e[i].w;
	}
for(int i=1;i<=n;i++)
	fi[i]=i;
for(int i=1;i<=k;i++){
	int a;
	cin>>a;
	for(int j=1;j<=n;j++){
		cin>>e[m+j].w;
		e[m+j].u=0;
		e[m+j].v=i;
		}
	}

sort(e+1,e+m+k+1,cmp);
for(int i=1;i<=m;i++){
	int fx=f(e[i].u),fy=f(e[i].v);
	if(fx==fy) continue;
	fi[fx]=fy;
	ans+=e[i].w;
	}
cout<<ans;
return 0;
}
