#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int tim,n,k,cnt[8];
long long ans,mxa,mxb,arr[N][8],jl[8][N];
long long maxx (long long a,long long b) {
	if(a>b) {
		return a;
	}
	return b;
}
int main () {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&tim);
	while(tim--) {
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		ans=0;
		scanf("%d",&n);
		k=n/2;
		for(int i=1;i<=n;i++) {
			mxa=0;
			mxb=0;
			scanf("%lld%lld%lld",&arr[i][1],&arr[i][2],&arr[i][3]);
			mxa=maxx(arr[i][1],maxx(arr[i][2],arr[i][3]));
			ans+=mxa;
			if(arr[i][1]==mxa) {
				mxb=maxx(arr[i][2],arr[i][3]);
				cnt[1]++;
				jl[1][cnt[1]]=(mxa-mxb);
			}else if(arr[i][2]==mxa) {
				mxb=maxx(arr[i][1],arr[i][3]);
				cnt[2]++;
				jl[2][cnt[2]]=(mxa-mxb);
			}else if(arr[i][3]==mxa) {
				mxb=maxx(arr[i][1],arr[i][2]);
				cnt[3]++;
				jl[3][cnt[3]]=(mxa-mxb);
			}
		}
		if(cnt[1]>k) {
			sort(jl[1]+1,jl[1]+cnt[1]+1);
			int tmp=cnt[1]-k;
			for(int i=1;i<=tmp;i++) {
				ans-=jl[1][i];
			}
		}else if(cnt[2]>k) {
			sort(jl[2]+1,jl[2]+cnt[2]+1);
			int tmp=cnt[2]-k;
			for(int i=1;i<=tmp;i++) {
				ans-=jl[2][i];
			}
		}else if(cnt[3]>k) {
			sort(jl[3]+1,jl[3]+cnt[3]+1);
			int tmp=cnt[3]-k;
			for(int i=1;i<=tmp;i++) {
				ans-=jl[3][i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
