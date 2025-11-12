#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define debug(a) cout<<#a<<"="<<a<<"\n";
using namespace std;
const long long N=2e5+7;
int n,a[N][4],ans;
vector<int> g[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		rep(i,1,3) g[i].clear();
		ans=0;
		scanf("%d",&n);
		rep(i,1,n){
			rep(j,1,3) scanf("%d",&a[i][j]);
		}
		rep(i,1,n){
			int id=1;
			rep(j,2,3){
				if(a[i][j]>a[i][id]) id=j;
			}
			int s=0;
			rep(j,1,3){
				if(id==j) continue;
				s=max(s,a[i][j]);
			}
			g[id].push_back(a[i][id]-s);
			ans+=a[i][id];
		}
		rep(i,1,3){
			if(g[i].size()>n/2){
				sort(g[i].begin(),g[i].end());
				rep(j,1,g[i].size()-n/2){
					ans-=g[i][j-1];
				}
			} 
		}
		printf("%d\n",ans);
	}
    return 0;
}
