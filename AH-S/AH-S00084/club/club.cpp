#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int T,a[N+5][3],n,sz[3],op[N+5],tmp,dt[N+5];
long long ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		sz[0]=sz[1]=sz[2]=ans=dt[0]=0; tmp=-1;
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			if (a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				sz[0]++; op[i]=0; ans+=a[i][0];
			} else if (a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				sz[1]++; op[i]=1; ans+=a[i][1];
			} else {
				sz[2]++; op[i]=2; ans+=a[i][2];
			}
		}
		for (int i=0;i<3;i++)
			if (sz[i]>n/2) tmp=i;
		if (tmp==-1){
			printf("%lld\n",ans);
		} else {
			for (int i=1;i<=n;i++){
				if (op[i]==tmp){
					dt[++dt[0]]=-1000000;
					for (int j=0;j<3;j++){
						if (j==tmp) continue;
						dt[dt[0]]=max(dt[dt[0]],a[i][j]-a[i][tmp]);
					}
				}
			}
			sort(dt+1,dt+dt[0]+1,cmp);
			for (int i=1;i<=sz[tmp]-n/2;i++) ans+=dt[i];
			printf("%lld\n",ans);
		}
	}
	
	
}
