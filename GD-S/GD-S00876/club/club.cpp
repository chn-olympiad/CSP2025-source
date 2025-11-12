#include<bits/stdc++.h>
using namespace std;
int a[100005][4],cnt[3];
int b[100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,ans=0,s=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			a[i][3]=max(a[i][0],max(a[i][1],a[i][2]));
			if(a[i][0]==a[i][3]) cnt[0]++,ans+=a[i][0];
			else if(a[i][1]==a[i][3]) cnt[1]++,ans+=a[i][1];
			else cnt[2]++,ans+=a[i][2];
		}
		if(cnt[0]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i][0]==a[i][3]){
					b[++s]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
				}
			}
			sort(b+1,b+s+1);cnt[0]-=n/2;
			for(int i=1;i<=cnt[0];i++) ans-=b[i];
		}
		else if(cnt[1]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i][0]!=a[i][3]&&a[i][1]==a[i][3]){
					b[++s]=min(a[i][3]-a[i][0],a[i][3]-a[i][2]);
				}
			}
			sort(b+1,b+s+1);cnt[1]-=n/2;
			for(int i=1;i<=cnt[1];i++) ans-=b[i];
		}
		else if(cnt[2]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i][0]!=a[i][3]&&a[i][1]!=a[i][3]&&a[i][2]==a[i][3]){
					b[++s]=min(a[i][3]-a[i][0],a[i][3]-a[i][1]);
				}
			}
			sort(b+1,b+s+1);cnt[2]-=n/2;
			for(int i=1;i<=cnt[2];i++) ans-=b[i];
		}
		cnt[0]=cnt[1]=cnt[2]=0;
		printf("%d\n",ans);
	}
	return 0;
}
