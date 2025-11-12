#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct xxx{
	int u,v,w;
}m[10005];

int c[15],a[15][10005];
int x[10005][10005];
int sum=0;
bool cmp(xxx x,xxx y){
	return x.w>y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>m[i].u>>m[i].v>>m[i].w;
		x[m[i].u][m[i].v]=1;
		sum+=m[i].w;		
	}
	if(k==0){
		sort(m+1,m+1+n,cmp);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[i][j]=1||x[j][i]=1){
					for(int k=1;k<=n;k++){
						if()
					}
				}
			}
		}
		return 0;
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++)
			cin>>a[j][i];		
	}

	return 0;
}
