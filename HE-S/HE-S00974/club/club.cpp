#include<cstdio>
#include<queue>
int t;
int n;
int a[100005][4];
std::priority_queue<int> prq[4];
int bg[4];
int ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			int pos=1,now=a[i][1],now1=0;
			for(int j=2;j<=3;j++){
				if(a[i][j]>now){
					now1=now;
					now=a[i][j];
					pos=j;
				}else if(a[i][j]>now1){
					now1=a[i][j];
				}
			}
			bg[pos]++,ans+=now;
			prq[pos].push(now1-now);
		}
		for(int i=1;i<=3;i++){
			if(bg[i]>(n>>1)){
				while(bg[i]>(n>>1)){
					bg[i]--;
					ans+=prq[i].top();
					prq[i].pop();
				}
				break;
			}
		}
		printf("%d\n",ans);
		bg[1]=bg[2]=bg[3]=0;
		for(int i=1;i<=3;i++){
			while(!prq[i].empty()){
				prq[i].pop();
			}
		}
		ans=0;
	}
	return 0;
}
