#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,sum=0,num=1,minsum=INT_MAX;
ll a[10001][10001],c[10000001],vis[10001][10001],vis2[1000001],f[1000001],x[10000001],h[10001];
void dfs(int start){
	if(num==n){
		minsum=min(sum,minsum);
		cout<<minsum<<endl;
		return;
	} 
	for(int i=1;i<=n;i++){
		memset(h,0,sizeof h);
		if(vis[start][i]==0 && i!=start){
			vis[start][i]=1;
			ll minn=INT_MAX;
			for(int j=1;j<=k;j++){
				if(f[j]==0){
					f[j]=1;
					h[j]++;
					minn=min(minn,a[start][j+n]+x[j]+a[j+n][i]);
				}else{
					minn=min(minn,a[start][j+n]+a[j+n][i]);
				}
			}
			ll nm=min(minn,a[start][i]);
			cout<<start<<" "<<i<<" "<<nm<<endl;
			sum+=nm;
			if(vis2[i]==0){
				vis2[i]=1;
				num++;
				dfs(i);
				num--;
				sum-=nm;
				vis[start][i]=0;
				f[i]=0;
				vis2[i]=0;
				for(int j=1;j<=k;j++){
					if(h[j]>0) f[j]=0; 
				}
			}else{
				dfs(i);
				sum-=nm;
				vis[start][i]=0;
				for(int j=1;j<=k;j++){
					if(h[j]>0) f[j]=0; 
				}
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	ll u,v,w;
	memset(a,0x3f,sizeof a);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&x[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&c[j]);
			a[n+i][j]=c[j];
			a[j][n+i]=c[j];
		}
	}
	vis2[1]=0;
	dfs(1);
	printf("%d",minsum);


	return 0;
	fclose(stdin);
	fclose(stdout);
}

