#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+30;
int n,m,k,ans=0;
int u[MAXN],v[MAXN],w[MAXN];
int t[MAXN][MAXN],c[11];
void mu(int x,int y, int z){
	if(t[x][z]==0 or t[y][z]==0)return ;
	if(t[x][y]>t[x][z]+t[z][y] or t[x][y]==0){
		t[y][x]=t[x][y]=t[x][z]+t[z][y];
	}
	
}
int main(){//死磕t2失败，没发现我写的这题的简单dp只是因为方向不对才错的，其实没问题，之前写的代码我删了，我还在闲逛时进回收站把它删了 
//完蛋，写点简单解法吧 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	cout<<"aiventi";
scanf("%d%d%d",&n,&m,&k);

for(int i=1;i<=m;i++){
	scanf("%d%d%d",&u[i],&v[i],&w[i]);
	if(t[u[i]][v[i]]==0)
	t[u[i]][v[i]]=t[v[i]][u[i]]=w[i];
	else t[u[i]][v[i]]=t[v[i]][u[i]]=min(w[i],t[u[i]][v[i]]);
}
for(int i=1;i<=k;i++){
	scanf("%d",&c[i]);
	for(int j=1,a;j<=n;j++){
	scanf("%d",&a);
	t[n+i][j]=t[j][n+i]=a;
	}
}
for(int i=1;i<=n+k;i++){
	for(int j=i+1;j<=n+k;j++)
	{
		for(int p=j+1;p<=n+k;p++){
				if(i!=p and j!=i and p!=j)
				{
			mu(j,i,p);
			mu(i,p,j);
			mu(j,p,i);}
		}
	}
}
for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++)
		ans=max(t[i][j],ans);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
} 
