#include<cstdio>
#include<vector>
#include<algorithm>
using std::vector;
using std::sort;
typedef long long ll;
int MAX(int x,int y){return x>y?x:y;}
int MIN(int x,int y){return x<y?x:y;}
const int N=1e6+8;
int T,n,a[N][3];
vector<int>b[3];
int sz[3];
int ans;
int c[N];
void solve(int x){
	int tot=0;
	for(int i=1;i<=n;i++) c[i]=2e9;
	for(int i=0;i<sz[x];i++){
		int id=b[x][i];
		tot++; 
		for(int j=0;j<=2;j++){
			if(j==x) continue;
			c[tot]=MIN(c[tot],a[id][x]-a[id][j]);
		}
//		printf("c[%d]=%d\n",tot,c[tot]);
	}
	sort(c+1,c+tot+1);
	for(int i=1;i<=sz[x]-n/2;i++) ans-=c[i];
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		b[0].clear();
		b[1].clear();
		b[2].clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) b[0].push_back(i);
			else if(a[i][1]>=a[i][2]) b[1].push_back(i);
			else b[2].push_back(i);
		}	
		sz[0]=b[0].size();
		sz[1]=b[1].size();
		sz[2]=b[2].size();
		for(int i=0;i<sz[0];i++){
			ans+=a[b[0][i]][0];
//			printf("0 id:%d\n",b[0][i]);
		}
		for(int i=0;i<sz[1];i++){
			ans+=a[b[1][i]][1];
//			printf("1 id:%d\n",b[1][i]);
		}
		for(int i=0;i<sz[2];i++){
			ans+=a[b[2][i]][2];
//			printf("2 id:%d\n",b[2][i]);
		}
		if(sz[0]>n/2) solve(0);
		else if(sz[1]>n/2) solve(1);
		else if(sz[2]>n/2) solve(2);
		printf("%d\n",ans);
	}
	return 0;
}
