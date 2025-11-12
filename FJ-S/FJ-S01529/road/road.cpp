#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,ans;
bool is[10005][10005];
struct iii{
	int u,v,w;
}a[1010005];
bool cmp(iii a,iii b){
	return a.w<b.w; 
}
bool ss(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(is[i][j]==false){
				return false;
			}
		}
	}
	return true;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	sort(a+1,a+n+1,cmp);
	int i=1;
	while(!ss(n)){
		is[a[i].u][a[i].v]=true;
		is[a[i].v][a[i].u]=true;
		ans+=a[i].w;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				for(int l=1;l<=n;l++){
					if((is[j][k]||is[k][j])&&(is[k][l]||is[l][k])){
						is[l][j]=true;
						is[j][l]=true;
					}
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
