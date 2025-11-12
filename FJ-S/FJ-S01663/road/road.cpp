#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int a[20][10010];
bool flag[10010];
long long sum;

struct xiufu{int u,v,w;}xf[1000010];
bool cmp(xiufu x,xiufu y){return x.w<y.w;}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>xf[i].u>>xf[i].v>>xf[i].w;
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
			cin>>a[i][j];
	sort(xf+1,xf+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(flag[xf[i].u] && flag[xf[i].v]) continue;
		else{
			if(!flag[xf[i].u] && !flag[xf[i].v]) {
				int minn=xf[i].w;
				for(int j=1;j<=k;j++)
					minn=min(minn,a[i][0]+a[i][xf[i].u]+a[i][xf[i].v]);
				sum+=minn;
			} 
		}
	}
	cout<<sum;
	return 0;
} 
