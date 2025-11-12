#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w,c[15],a[15][10005],b[10005][10005];
long z,xz,l[1000005],t[1000005];
void f(int x,int y){
	if(x==n){
		if(z>=xz){
			z=xz;
		}
		return;
	}
	if(t[x]==2) return;
	for(int i=1;i<=n;i++){
		if(t[i]<2){
			xz+=b[x][i];
			t[x]++;
			t[i]++;
			l[y]=b[x][i];
			f(x+1,y+1);
			t[x]--;
			t[i]--;
			xz-=b[x][i];
		}		
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++){
		scanf("%d",&u,&v,&w);
		b[u][v]=w;
		b[v][u]=w;
		b[i][i]=0;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
		for(int x=2;x<=n;x++){
			for(int j=1;j<i;j++){
				if(b[x][j]>a[i][x]+a[i][j]){
					b[x][j]=a[i][x]+a[i][j];
					b[j][x]=a[i][x]+a[i][j];
				}
			}
		}
	}
	f(1,1);
	sort(l+1,l+1+n);
	z-=l[n];
	cout<<z;
	return 0;
} 
