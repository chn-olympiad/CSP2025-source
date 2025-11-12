#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int r[N][N]={-10};
int n,m,k,a,x,mm,maxx;
long long ma;
bool b[N];
int solve(){
	b[0]=1;
	for(;x!=0;){
	for(int i=0;i<n;i++){
		mm=maxx;
		if(b[i])
		for(int j=0;j<n;j++){
			if(r[i][j]!=-10&&!b[j]){
				if(mm>r[i][j]){
				mm=r[i][j];
				x=j;
				}
			}
		}
		b[x]=1;
		ma+=mm;
	}
	x=0;
	for(int i=0;i<n;i++){
		if(!b[i]){
			x=1;
			break;
		}
	}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int i1=n;i1<n+k;i1++){
				if(r[i][j]>r[i][i1]+r[i1][j]&&r[i][j]!=-10&&r[i][i1]!=-10&&r[i1][j]!=-10){
					ma=ma-r[i][j]+r[i][i1]+r[i1][j];
				}
			}
		}
	}
	printf("%lld",ma);
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a,&x,&r[a][x]);
		maxx=max(maxx,r[a][x]);
		r[x][a]=r[a][x];
	}
	for(int i=0;i<k;i++){
		scanf("%d",&a);
		for(int j=0;j<k;j++){
			scanf("%d",&x);
			r[n+i][n+j]=a+x;
			r[n+j][n+i]=a+x;
		}
	}
	solve(); 
	return 0;
} 
