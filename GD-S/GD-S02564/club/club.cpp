#include<bits/stdc++.h>
using namespace std;
int t,n;
long long a[100005][4],dp[100005],num[4],co,p,k,q[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		p=k=co=0;
		num[1]=num[2]=num[3]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				num[1]++;
				dp[i]=1;
				co+=a[i][1];
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				num[2]++;
				dp[i]=2;
				co+=a[i][2];
			}else{
				num[3]++;
				dp[i]=3;
				co+=a[i][3];
			}
		}
		if(num[1]>n/2){
			p=num[1]-(n/2);
			for(int i=1;i<=n;i++){
				if(dp[i]==1){
					q[++k]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
				}
			}
		}else if(num[2]>n/2){
			p=num[2]-(n/2);
			for(int i=1;i<=n;i++){
				if(dp[i]==2){
					q[++k]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
				}
			}
		}else if(num[3]>n/2){
			p=num[3]-(n/2);
			for(int i=1;i<=n;i++){
				if(dp[i]==3){
					q[++k]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
				}
			}
		}
		sort(q+1,q+1+k);
		for(int i=1;i<=p;i++){
			co-=q[i];
		}
		printf("%d\n",co);
	}
	return 0;
}
