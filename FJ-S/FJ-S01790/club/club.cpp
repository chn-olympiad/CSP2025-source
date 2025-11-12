#include<bits/stdc++.h> 
using namespace std;
const int N=1e5+5;
int t,n,qwq;
int a[N][4];
long long dp[N],yefeng[9];
int q1,q2,q3;
int vis[N],cha[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
    	int cnt=0;
    	cin>>n;
    	q1=0;
    	q2=0;
    	q3=0;
    	memset(vis,0,sizeof(vis));
    	memset(cha,0,sizeof(cha));
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=3;j++){
    			scanf("%d",&a[i][j]);
			}
			dp[i]=dp[i-1]+max(a[i][1],max(a[i][2],a[i][3]));
			if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][1]){
				q1++;
				vis[i]=1;
			}else if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][2]){
				q2++;
				vis[i]=2;
			}else if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][3]){
				q3++;
				vis[i]=3;
			}
		}
		if(q1>n/2){
			for(int i=1;i<=n;i++){
				if(vis[i]==1){
					cha[++cnt]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
				}
			}
			sort(cha+1,cha+cnt+1);
			for(int i=1;i<=q1-n/2;i++){
				dp[n]-=cha[i];
			}
		}
		if(q2>n/2){
			for(int i=1;i<=n;i++){
				if(vis[i]==2){
					cha[++cnt]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
				}
			}
			sort(cha+1,cha+cnt+1);
			for(int i=1;i<=q2-n/2;i++){
				dp[n]-=cha[i];
			}
		}
		if(q3>n/2){
			for(int i=1;i<=n;i++){
				if(vis[i]==3){
					cha[++cnt]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
				}
			}
			sort(cha+1,cha+cnt+1);
			for(int i=1;i<=q3-n/2;i++){
				dp[n]-=cha[i];
			}
		}
		yefeng[++qwq]=dp[n];
	}
	for(int i=1;i<=qwq;i++){
		cout<<yefeng[i]<<"\n";
	}
	return 0;
}
