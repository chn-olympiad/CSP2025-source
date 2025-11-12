#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m,k;
int num=0,sum=0;
int f[10005];
struct p{
	int u;
	int v;
	int w;
}e[200000];

bool cmp(p a,p b){
	return a.w<b.w;
}

int find(int a){
	if (f[a]!=a)return find(f[a]);
	if(f[a]==a)return a;
}

void prim(){
	sum=0;
	for(int i=1;i<=k+m;i++){
		f[e[i].u]=e[i].u;
		f[e[i].v]=e[i].v;
	}
	for(int i=1;i<=m+k;i++){
		if(f[e[i].u]!=f[e[i].v]){
			f[e[i].u]=find(f[e[i].v]);
			sum+=e[i].w;
		}
		int p=1;
		for(int j=1;j<=n;j++){
			if(f[j]!=f[j+1]){
				p=0;break;
			}
		}
		if(p==1){
			num=min(num,sum);
			return;
		}
	}
}


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i].u=u;
		e[i].v=v;
		e[i].  w=w;
	}
	 

	for(int i=m;i<=k+m;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			e[i].u=i;
			e[i]. v=j;
			e[i].w=w+c;
		}
	}
	sort(e+1,e+1+k+m,cmp);
		prim();
	cout<<num;
	return 0;
}
