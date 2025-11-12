#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][4],ans,b[4],c[N],d[N],x,tot; 
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>t;
	while (t--) {
		cin >>n;
		for (int i=1;i<=n;i++) {
			cin >>a[i][1]>>a[i][2]>>a[i][3];
		}
		b[1]=b[2]=b[3]=0;
		tot=0;
		ans=x=0;
		for (int i=1;i<=n;i++) {
			int cnt=-1,cnti=0;
			for (int j=1;j<=3;j++) {
				if (cnt<a[i][j]) {
					cnt=a[i][j];
					cnti=j;
				}
			}
			c[i]=cnti;
			b[cnti]++;
			ans+=cnt;
		}
		if (b[1]>n/2||b[2]>n/2||b[3]>n/2) {
			x=(b[1]>n/2?1:(b[2]>n/2?2:3));
		} else {
			cout <<ans<<"\n";
			continue;
		}
		for (int i=1;i<=n;i++) {
			if (c[i]==x) {
				if (x==1) d[++tot]=min(a[i][x]-a[i][2],a[i][x]-a[i][3]);
				else if (x==2) d[++tot]=min(a[i][x]-a[i][1],a[i][x]-a[i][3]);
				else d[++tot]=min(a[i][x]-a[i][1],a[i][x]-a[i][2]);
			}
		}
		sort(d+1,d+tot+1);
		for (int i=1;i<=b[x]-n/2;i++) {
			ans-=d[i];
		} 
		cout <<ans<<"\n";
	} 
	return 0;
}
