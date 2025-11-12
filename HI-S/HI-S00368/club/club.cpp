#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5+10;


int t;
int n,ans=0;

struct edge {
	int bm[5];
	int bm_f,bm_s,bm_t;
} a[MAXN];

bool cmp(edge x,edge y){
	return x.bm[x.bm_f]>y.bm[y.bm_f];
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	scanf("%d",&t);
	while(t--) {
		ans=0;
		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			scanf("%d%d%d",&a[i].bm[1],&a[i].bm[2],&a[i].bm[3]);
			if(a[i].bm[1]>=a[i].bm[2]&&a[i].bm[1]>=a[i].bm[3]) {
				a[i].bm_f=1;
				if(a[i].bm[2]>=a[i].bm[3]) {
					a[i].bm_s=2;
					a[i].bm_t=3;
				} else {
					a[i].bm_s=3;
					a[i].bm_t=2;
				}
			}
			if(a[i].bm[2]>=a[i].bm[1]&&a[i].bm[2]>=a[i].bm[3]) {
				a[i].bm_f=2;
				if(a[i].bm[1]>=a[i].bm[3]) {
					a[i].bm_s=1;
					a[i].bm_t=3;
				} else {
					a[i].bm_s=3;
					a[i].bm_t=1;
				}
			}
			if(a[i].bm[3]>=a[i].bm[1]&&a[i].bm[3]>=a[i].bm[2]) {
				a[i].bm_f=3;
				if(a[i].bm[1]>=a[i].bm[2]) {
					a[i].bm_s=1;
					a[i].bm_t=2;
				} else {
					a[i].bm_s=2;
					a[i].bm_t=1;
				}
			}
		}
		if(n==2) {
			if(a[1].bm_f==a[2].bm_f){
				ans=max(a[1].bm[a[1].bm_f]+a[2].bm[a[2].bm_s],ans);
				ans=max(a[1].bm[a[1].bm_s]+a[2].bm[a[2].bm_f],ans);
			}else ans=ans+a[1].bm[a[1].bm_f]+a[2].bm[a[2].bm_f];
			printf("%d\n",ans);
		} else {
			sort(a+1,a+1+n,cmp);
			int ji1=1,ji2=1,ji3=1;
			for(int i=1;i<=n;i++){
				if(a[i].bm_f==1&&ji1<=n/2){
					ans+=a[i].bm[a[i].bm_f]; 
					ji1++;
				}
				if(a[i].bm_f==2&&ji2<=n/2){
					ans+=a[i].bm[a[i].bm_f];
					ji2++;
				}
				if(a[i].bm_f==3&&ji3<=n/2){
					ans+=a[i].bm[a[i].bm_f];
					ji3++;
				}				
			}
			printf("%d\n",ans);	
		}
	}
	return 0;
}

