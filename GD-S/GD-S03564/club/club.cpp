#include<bits/stdc++.h>
#define Mp make_pair
#define eb emplace_back
#define il inline
#define pc putchar
#define gc getchar
#define mems(x,y) memset(x,y,sizeof x)
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define drep(i,x,y) for(int i=(x);i>=(y);i--)
#define go(i,u) for(int i=head[u];i;i=e[i].nxt)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=-1,M=-1,inf=0x3f3f3f3f,mod=0;
const ll INF=1ll*inf*inf;
int n,m;
vector<int> g[3];
void Sana(){
	scanf("%d",&n);
	rep(i,0,2){
		g[i].clear();
	}
	int ans=0;
	rep(i,1,n){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		ans+=max({x,y,z});
		if(x>=y&&x>=z){
			g[0].eb(x-max(y,z));
		}else if(y>=z){
			g[1].eb(y-max(x,z));
		}else{
			g[2].eb(z-max(x,y));
		}
	}
	rep(i,0,2){
		if(g[i].size()>n/2){
			sort(g[i].begin(),g[i].end());
			rep(j,1,(int)g[i].size()-n/2){
				ans-=g[i][j-1];
			}
		}
	}
	printf("%d\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=1;
	scanf("%d",&t);
	while(t--){	
		Sana();
	}
}
