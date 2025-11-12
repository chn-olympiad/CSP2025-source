#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node {
	int f,s,t;
	int best,cha;
} a[100005];
int b[15];
int cmp(node a,node b) {
	if(a.cha<b.cha)return 1;
	return 0;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		for(int i=6; i>0; i--) {

			b[i]=0;

		}
		cin>>n;
		int ans=0;
		for(int i=1; i<=n; i++) {
			scanf("%d %d %d",&a[i].f,&a[i].s,&a[i].t);
			if(a[i].f>=a[i].s&&a[i].f>=a[i].t) {
				a[i].best=1;
				ans+=a[i].f;
			} else if(a[i].s>=a[i].f&&a[i].s>=a[i].t) {
				a[i].best=2;
				ans+=a[i].s;
			} else {
				a[i].best=3;
				ans+=a[i].t;
			}
			a[i].cha=min(a[i].f,min(a[i].t,a[i].s))+max(a[i].f,max(a[i].t,a[i].s))*2-(a[i].f+a[i].s+a[i].t);
			b[a[i].best]++;
		}
		int s=0,ss=0;
		for(int i=1; i<=3; i++) {
			if(b[i]>n/2)s=b[i]-n/2,ss=i;
		}
		if(s>0) {
			sort(a+1,a+n+1,cmp);

			for(int i=1; i<=n,s>0; i++) {
				if(a[i].best==ss) {
					ans-=a[i].cha;
					s--;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


