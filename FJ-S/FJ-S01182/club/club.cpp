#include<bits/stdc++.h>
using namespace std;
long long t,n,cnt[4],ans;
struct c{
	long long nu,id;
} c1[200005],c2[200005],c3[200005];
bool cmp(c A,c B){
	return A.nu<=B.nu;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		ans=cnt[1]=cnt[2]=cnt[3]=0;
		for(long long i=1,n1,n2,n3;i<=n;i++){
			scanf("%lld%lld%lld",&n1,&n2,&n3);
			if(n1>=n2&&n1>=n3){
				cnt[1]++;
				c1[cnt[1]]={n1-max(n2,n3),i};
				ans+=n1;
			}
			else{
				if(n2>=n1&&n2>=n3){
					cnt[2]++;
					c2[cnt[2]]={n2-max(n1,n3),i};
					ans+=n2;
				}
				else{
					cnt[3]++;
					c3[cnt[3]]={n3-max(n1,n2),i};
					ans+=n3;
				}
			}
		}
		if(cnt[1]>n/2){
			sort(c1+1,c1+1+cnt[1],cmp);
			long long res=cnt[1]-n/2;
			for(long long i=1;i<=cnt[1];i++){
				res--;
				ans-=c1[i].nu;
				if(res==0) break;
			}
		}
		if(cnt[2]>n/2){
			sort(c2+1,c2+1+cnt[2],cmp);
			long long res=cnt[2]-n/2;
			for(long long i=1;i<=cnt[2];i++){
				res--;
				ans-=c2[i].nu;
				if(res==0) break;
			}
		}
		if(cnt[3]>n/2){
			sort(c3+1,c3+1+cnt[3],cmp);
			long long res=cnt[3]-n/2;
			for(long long i=1;i<=cnt[3];i++){
				res--;
				ans-=c3[i].nu;
				if(res==0) break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}