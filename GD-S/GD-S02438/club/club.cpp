#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int ans;
int full[(int)(1e5+5)][3];
bool flag[(int)(1e5+5)];
int cost[3];
int T,n;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=n;i++)
		{
			ans=full[i][0]=full[i][1]=full[i][2]=cost[0]=cost[1]=cost[2]=0;
			flag[i]=false;
		}
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf(" %d %d %d",&full[i][0],&full[i][1],&full[i][2]);
		}
		for(int i=1;i<=n;i++){
			if(full[i][0]>=full[i][1]){
				if(full[i][0]>=full[i][2]){
					cost[0]++;
					ans+=full[i][0];
				}
				else {
					cost[2]++;
					ans+=full[i][2];
				}
			}
			else if(full[i][2]>=full[i][1]){
				cost[2]++;
				ans+=full[i][2];
			}
			else{
				cost[1]++;
				ans+=full[i][1];
			}
		}
		int maxc,maxp;
		if(cost[0]>=cost[1]){
			if(cost[0]>=cost[2]){
				maxc=cost[0];
				maxp=0;
			}
			else {
				maxc=cost[2];
				maxp=2;
			}
		}
		else if(cost[2]>=cost[1]){
			maxc=cost[2];
			maxp=2;
		}
		else{
			maxc=cost[1];
			maxp=1;
		}
		for(int mpoint,mflag;maxc>n/2;maxc--){
			mpoint=2e9,mflag=0;
			for(int i=1;i<=n;i++){
				if(flag[i]) continue;
				if(full[i][maxp]-full[i][(maxp+2)%3]<mpoint){
					mpoint=full[i][maxp]-full[i][(maxp+2)%3];
					mflag=i;
				}
				if(full[i][maxp]-full[i][(maxp+1)%3]<mpoint){
					mpoint=full[i][maxp]-full[i][(maxp+1)%3];
					mflag=i;
				}
			}
			flag[mflag]=true;
			ans-=mpoint;
		}
		printf("%d\n",ans);
	}
	
	return 0;	
}
