#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1000;
int T,m,n,ans,f1,f2;
int a[N][4];
int g[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		m=n/2;
		memset(g,0,sizeof(g));
		memset(dp,0,sizeof(dp));
		ans=0; f1=0; f2=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
			f1+=a[i][2]; f2+=a[i][3];
		}
		if(f1==0&&f2==0){
			for(int i=1;i<=n;i++){
				g[i]=a[i][1];
			}
			sort(g+1,g+1+n,cmp);
			for(int i=1;i<=m;i++) ans+=g[i];
			printf("%d\n",ans);
		}
	}
	return 0;
}
