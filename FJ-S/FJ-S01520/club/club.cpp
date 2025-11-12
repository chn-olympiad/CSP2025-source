#include<bits/stdc++.h>
using namespace std;
const int N=100020;
int thres,n,cnt[5],ans,a[N][5],col[N],dlt[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("F:/down/club/club5.in","r",stdin);
//	freopen("club.txt","w",stdout);
	scanf("%d",&thres);
	while(thres--){
		scanf("%d",&n);
		cnt[0]=cnt[1]=cnt[2]=ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				ans+=a[i][0];cnt[0]++;col[i]=0;
			}else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				ans+=a[i][1];cnt[1]++;col[i]=1;
			}else if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1]){
				ans+=a[i][2];cnt[2]++;col[i]=2;
			}
		}
		if(cnt[0]>n/2||cnt[1]>n/2||cnt[2]>n/2){
			if(cnt[0]>n/2)
				for(int i=1;i<=n;i++){
					if(col[i]==0)
						dlt[i]=a[i][0]-max(a[i][1],a[i][2]);
					else dlt[i]=0x3f3f3f3f;
				}
			if(cnt[1]>n/2)
				for(int i=1;i<=n;i++){
					if(col[i]==1)
						dlt[i]=a[i][1]-max(a[i][0],a[i][2]);
					else dlt[i]=0x3f3f3f3f;
				}
			if(cnt[2]>n/2)
				for(int i=1;i<=n;i++){
					if(col[i]==2)
						dlt[i]=a[i][2]-max(a[i][0],a[i][1]);
					else dlt[i]=0x3f3f3f3f;
				}
			int temp=max(cnt[0],max(cnt[1],cnt[2]));
			sort(dlt+1,dlt+1+n);
			for(int i=1;i<=temp-(n/2);i++)
				ans-=dlt[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
