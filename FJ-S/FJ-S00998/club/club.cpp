#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,INF=0x3f3f3f3f;
int a[N][5],n,wl[N],mx[N],sz[5];
void init(){
	for(int i=1;i<=4;i++){
		sz[i]=0;
	}
}
priority_queue<pair<int,int> > q1,q2,q3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;
	scanf("%d",&_);
	while(_--){
		int ans;
		ans=0;
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]<=a[i][3]){
				wl[i]=a[i][3]-a[i][1];
				mx[i]=3;
			}else if(a[i][3]>=a[i][2]&&a[i][1]<=a[i][2]){
				wl[i]=a[i][3]-a[i][2];
				mx[i]=3;
			}else if(a[i][1]>=a[i][2]&&a[i][3]<=a[i][2]){
				wl[i]=a[i][1]-a[i][2];
				mx[i]=1;
			}else if(a[i][1]>=a[i][3]&&a[i][2]<=a[i][3]){
				wl[i]=a[i][1]-a[i][3];
				mx[i]=1;
			}else if(a[i][2]>=a[i][3]&&a[i][1]<=a[i][3]){
				wl[i]=a[i][2]-a[i][3];
				mx[i]=2;
			}else{
				wl[i]=a[i][2]-a[i][1];
				mx[i]=2;
			}
		}
		for(int i=1;i<=n;i++){
			if(mx[i]==1){
				q1.push({-wl[i],i});
			}else if(mx[i]==2){
				q2.push({-wl[i],i});
			}else{
				q3.push({-wl[i],i});
			}
			sz[mx[i]]++;
			if(sz[mx[i]]>(n/2)){
				sz[mx[i]]--;
				int u;
				if(mx[i]==1){
					u=q1.top().second;
					q1.pop();
				}else if(mx[i]==2){
					u=q2.top().second;
					q2.pop();
				}else{
					u=q3.top().second;
					q3.pop();
				}
				if(a[u][1]>=a[u][2]&&a[u][1]<=a[u][3]){
					q1.push({-INF,u});
				}else if(a[u][3]>=a[u][2]&&a[u][1]<=a[u][2]){
					q2.push({-INF,u});
				}else if(a[u][1]>=a[u][2]&&a[u][3]<=a[u][2]){
					q2.push({-INF,u});
				}else if(a[u][1]>=a[u][3]&&a[u][2]<=a[u][3]){
					q3.push({-INF,u});
				}else if(a[u][2]>=a[u][3]&&a[u][1]<=a[u][3]){
					q3.push({-INF,u});
				}else{
					q1.push({-INF,u});
				}	
			}
		}
		while(!q1.empty()){
			int u=q1.top().second;q1.pop();ans+=a[u][1];
		}
		while(!q2.empty()){
			int u=q2.top().second;q2.pop();ans+=a[u][2];
		}
		while(!q3.empty()){
			int u=q3.top().second;q3.pop();ans+=a[u][3];
		}printf("%d\n",ans);
	}
	return 0;
}
