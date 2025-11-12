#include<bits/stdc++.h>
using namespace std;
long long t,n,i,j;
long long a[100005][5];
long long id[100005],sum[5];
long long c[100005],l=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		long long ans=0;
		sum[1]=0;sum[2]=0;sum[3]=0;
		for(i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			long long maxn=max(a[i][1],max(a[i][2],a[i][3]));
			ans+=maxn;
			for(j=1;j<=3;j++){
				if(a[i][j]==maxn){
					sum[j]++;
					id[i]=j;
					break;
				}
			}
		}
		long long flag=0;
		for(i=1;i<=3;i++){
			if(sum[i]>n/2){
				flag=i;
				break;
			}
		}
		if(flag==0){
			printf("%lld\n",ans);
		}else{
			l=0;
			for(i=1;i<=n;i++){
				if(id[i]==flag){
					long long maxn=0;
					for(j=1;j<=3;j++){
						if(id[i]!=j){
							maxn=max(maxn,a[i][j]);
						}
					}
					c[++l]=a[i][id[i]]-maxn;
				}
			}
			sort(c+1,c+l+1);
			for(i=1;i<=sum[flag]-(n/2);i++){
				ans-=c[i];
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
