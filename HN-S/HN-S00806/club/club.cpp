#include<bits/stdc++.h>
using namespace std;
struct student {
	int d[4];
	int a_b;
};
bool cmp(student x,student y) {
	return x.a_b<y.a_b;
}
student a[100010];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	scanf("%d",&t);
	while(t--) {
		int sum1=0;
		int sum2=0;
		int ans=0;
		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				scanf("%d",&a[i].d[j]);
				a[i].a_b=a[i].d[2]-a[i].d[1];
			}
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1; i<=n/2; i++) {
			ans+=a[i].d[1];
		}
		for(int i=n; i>=1&&sum1<n/2; i--) {
			if(a[i].a_b==0) {
				ans+=a[i].d[1];
			}
			ans+=a[i].d[2];
			sum1++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
