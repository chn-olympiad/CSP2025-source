#include<bits/stdc++.h> 
#define ll long long
using namespace std;
struct dd{
	int i,x;
}a[21],b[100005];
bool comp(dd ai,dd bi){
	return ai.x<bi.x;
}
int n,m,t,c[100005],sum[21];
ll ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		sum[1]=0,sum[2]=0,sum[3]=0;
		for(int i=1;i<=n;i++){
			a[1].i=1,a[2].i=2,a[3].i=3;
			scanf("%d%d%d",&a[1].x,&a[2].x,&a[3].x);
			sort(a+1,a+1+3,comp);
			b[i].x=a[3].x-a[2].x;
			c[i]=a[3].x;
			b[i].i=a[3].i;
			ans+=a[3].x;
			sum[a[3].i]++;
		}
		for(int z=1;z<=3;z++){
			if(sum[z]>n/2){
				sort(b+1,b+1+n,comp);
				for(int i=1,j=1;i<=sum[z]-n/2;i++,j++){
					while(b[j].i!=z)j++;
					ans-=b[j].x;
				}
				break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
