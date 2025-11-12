# include <bits/stdc++.h>
using namespace std;
int a[10001][10001],n,m,k,dis[10001];
bool f[10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int ans=0;
	for(int q=1;q<=m;q++){
		int z,x,c;
		scanf("%d%d%d",&z,&x,&c);
		a[z][x]=c;
		a[x][z]=c;
		ans+=c;
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) a[i][i]=0,f[i]=0;
	f[1]=1;
	dis[1]=0;
	for(int i=1;i<=n;i++){
		int x=-1;
		for(int j=1;j<=n;j++){
			if(f[j]==0&&(x==-1||dis[x]>dis[j])){
				x=j;
			}
		}
		cout<<x;
		f[x]=1;
		for(int j=1;j<=n;j++){
			if(a[j][x]>0&&f[j]==0){
				dis[j]=min(dis[x]+a[j][x],dis[j]);
			}
		}
	}
	for(int q=1;q<=n;q++){
		cout<<dis[q];
	}
	cout<<c;
}
