#include <bits/stdc++.h>
#define ll long long
using namespace std;
int T,n,a[5],cnt[5];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	scanf("%d",&T);
	while(T--) {
		for(int i=1;i<=3;i++) cnt[i]=0;
		scanf("%d",&n);
		int mxn1=0,mxn2=0;
		ll ans=0;
		priority_queue <int,vector<int>,greater<int> > pq1,pq2,pq3;
		for(int i=1;i<=n;i++) {
			scanf("%d%d%d",&a[1],&a[2],&a[3]);
			if(a[1]>=a[2]&&a[2]>=a[3]) {
				mxn1=a[1],mxn2=a[2];
				cnt[1]++;
				pq1.push(mxn1-mxn2);
			}
			else if(a[1]>=a[3]&&a[3]>=a[2]) {
				mxn1=a[1],mxn2=a[3];
				cnt[1]++;
				pq1.push(mxn1-mxn2);
			}
			else if(a[2]>=a[1]&&a[1]>=a[3]) {
				mxn1=a[2],mxn2=a[1];
				cnt[2]++;
				pq2.push(mxn1-mxn2);
			}
			else if(a[2]>=a[3]&&a[3]>=a[1]) {
				mxn1=a[2],mxn2=a[3];
				cnt[2]++;
				pq2.push(mxn1-mxn2);
			}
			else if(a[3]>=a[1]&&a[1]>=a[2]) {
				mxn1=a[3],mxn2=a[1];
				cnt[3]++;
				pq3.push(mxn1-mxn2);
			}
			else if(a[3]>=a[2]&&a[2]>=a[1]) {
				mxn1=a[3],mxn2=a[2];
				cnt[3]++;
				pq3.push(mxn1-mxn2);
			}
			ans+=mxn1;
		}
		int tmp=n/2;
		if(cnt[1]>tmp) {
			int c=cnt[1]-tmp;
			for(int i=1;i<=c;i++) {
				ans-=pq1.top();
				pq1.pop();
			}
		}
		else if(cnt[2]>tmp) {
			int c=cnt[2]-tmp;
			for(int i=1;i<=c;i++) {
				ans-=pq2.top();
				pq2.pop();
			}
		}
		else if(cnt[3]>tmp) {
			int c=cnt[3]-tmp;
			for(int i=1;i<=c;i++) {
				ans-=pq3.top();
				pq3.pop();
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
