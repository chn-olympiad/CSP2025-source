#include<stdio.h>
#include<algorithm>
#include<vector>
const int N=1e5+5;
std::vector<int> v;
int t,n,a[N][3],vis[N],count[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<3;i++) count[i]=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			int maxn=-0x3f3f3f3f,p=-1;
			for(int j=0;j<3;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]>maxn) maxn=a[i][j],p=j; 
			}
			ans+=maxn,vis[i]=p,count[p]++;
		}
		int p=-1;
		for(int i=0;i<3;i++) if(count[i]>(n>>1)){p=i;break;}
		if(p!=-1){
			v.clear();
			for(int i=1;i<=n;i++){
				if(vis[i]==p){
					int maxn=-0x3f3f3f3f;
					for(int j=0;j<3;j++) if(j!=p) maxn=std::max(maxn,a[i][j]-a[i][p]);
					v.emplace_back(maxn);
				}
			}
			std::sort(v.begin(),v.end(),[](int x,int y){return x>y;});
			for(int i=0;i<count[p]-(n>>1);i++) ans+=v[i];
		}
		printf("%d\n",ans); 
	}
	return 0;
} 
