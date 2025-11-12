#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int T,n,a[N][3],q[3][N],m[3],b[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		m[0]=m[1]=m[2]=0;
		long long ans=0;
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			int k=0;
			for(int j=1;j<=2;++j){
				if(a[i][j]>a[i][k])k=j;
			}
			q[k][++m[k]]=i;
			ans+=a[i][k];
		}
		int k=-1;
		for(int i=0;i<=2;++i)if(m[i]>n/2)k=i;
		if(k!=-1){
			for(int i=1;i<=m[k];++i){
				int maxn=-1e9;
				for(int j=0;j<=2;++j)if(j!=k)maxn=max(maxn,a[q[k][i]][j]);
				maxn-=a[q[k][i]][k];
				b[i]=maxn;
			}
			sort(b+1,b+m[k]+1);
			reverse(b+1,b+m[k]+1);
			for(int i=1;i<=m[k]-n/2;++i)ans+=b[i];
		}
		printf("%lld\n",ans);
	}
}
