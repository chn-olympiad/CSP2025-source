#include<bits/stdc++.h>
using namespace std;
int T,n,a[200010][5],b[5],cnt,t[200010];
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%d",&n);
		ans=0;
		cnt=0;
		b[1]=0;
		b[2]=0;
		b[3]=0;
		for (int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if (a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				a[i][0]=1;
				b[1]++;
				ans+=a[i][1];
			}else if (a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				a[i][0]=2;
				b[2]++;
				ans+=a[i][2];
			}else{
				a[i][0]=3;
				b[3]++;
				ans+=a[i][3];
			}
		}
		if (b[1]<=n/2&&b[2]<=n/2&&b[3]<=n/2){
			printf("%lld\n",ans);
			continue;
		}
		if (b[1]>n/2){
			for (int i=1;i<=n;i++){
				if (a[i][0]==1){
					if (a[i][1]-a[i][2]<a[i][1]-a[i][3]){
						t[++cnt]=a[i][1]-a[i][2];
					}else{
						t[++cnt]=a[i][1]-a[i][3];
					}
				}
			}
			sort(t+1,t+1+cnt);
			for (int i=1;i<=b[1]-n/2;i++){
				ans-=t[i];
			}
		}
		if (b[2]>n/2){
			for (int i=1;i<=n;i++){
				if (a[i][0]==2){
					if (a[i][2]-a[i][1]<a[i][2]-a[i][3]){
						t[++cnt]=a[i][2]-a[i][1];
					}else{
						t[++cnt]=a[i][2]-a[i][3];
					}
				}
			}
			sort(t+1,t+1+cnt);
			for (int i=1;i<=b[2]-n/2;i++){
				ans-=t[i];
			}
		}
		if (b[3]>n/2){
			for (int i=1;i<=n;i++){
				if (a[i][0]==3){
					if (a[i][3]-a[i][1]<a[i][3]-a[i][2]){
						t[++cnt]=a[i][3]-a[i][1];
					}else{
						t[++cnt]=a[i][3]-a[i][2];
					}
				}
			}
			sort(t+1,t+1+cnt);
			for (int i=1;i<=b[3]-n/2;i++){
				ans-=t[i];
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
