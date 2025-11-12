#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+10;
#define ll long long
int T,n,i,j,cnt[3],amax[N],cmax;
ll a[N][3],ans,ad[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		memset(ad,0x3f,sizeof(ad));
		memset(amax,0,sizeof(amax));
		ans=0;
		for(i=1;i<=n;++i){
			scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
			for(j=1;j<3;++j){
				if(a[i][j]>a[i][amax[i]]) amax[i]=j;
			}
			++cnt[amax[i]],ans+=a[i][amax[i]];
		}
		cmax=0;
		if(cnt[1]>cnt[0]) cmax=1;
		if(cnt[2]>cnt[cmax]) cmax=2;
		if(cnt[cmax]>(n>>1)){
			for(i=1;i<=n;++i){
				if(amax[i]!=cmax) continue;
				for(j=0;j<3;++j){
					if(j!=cmax) ad[i]=min(-a[i][j]+a[i][cmax],ad[i]);
				}
			}
			sort(ad+1,ad+1+n);
			for(i=1;i<=cnt[cmax]-(n>>1);++i) ans-=ad[i];
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//14:56(57)-15:28(29)
