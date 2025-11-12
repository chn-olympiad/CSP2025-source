//GZ-S00433 遵义市第四中学 邓嘉瑶
#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][4];
bool cmp(int x,int y) {
	return x>y;
}
int l3[100005],l1[100005],l2[100005],h3[100005],h1[100005],h2[100005],cnt=0;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		long long sum=0;
		cin>>n;
		cnt=0;
		memset(l1,0,sizeof(0));
		memset(l2,0,sizeof(0));
		memset(l3,0,sizeof(0));
		for(int i=1; i<=n; i++) {
			cnt++;
			for(int j=1; j<=3; j++) {
				cin>>a[i][j];
				l1[cnt]=a[i][1];
				l2[cnt]=a[i][2];
				l3[cnt]=a[i][3];
				h1[l1[cnt]]=i;
				h2[l2[cnt]]=i;
				h3[l3[cnt]]=i;
			}
		}
		sort(l1+1,l1+cnt+1,cmp);
		sort(l2+1,l2+cnt+1,cmp);
		sort(l3+1,l3+cnt+1,cmp);
		bool pd2=1,pd3=1;
		for(int i=1; i<=cnt; i++) {
			if(l2[i]!=0) {
				pd2=0;
			}
			if(l3[i]!=0) {
				pd3=0;
			}
		}
		if(pd3==1&&pd2==1) {
			for(int i=1; i<=n/2; i++) {
				sum+=l1[i];
			}
			cout<<sum<<endl;
			continue;
		}
		int r1=n/2,r2=n/2,vis[n+1];
		memset(vis,0,sizeof(0));
		if(pd3==1&&pd2==0) {
			for(int i=1; i<=n/2; i++) {
				if(h1[l1[i]]==h2[l2[i]]) {
					if(l1[i]>l2[i]) {
						sum+=l1[i];
						vis[h1[l1[i]]]=1;
						r1--;
					} else {
						sum+=l2[i];
						vis[h2[l2[i]]]=1;
						r2--;
					}
				}
			}
			for(int i=1; i<=n; i++) {
				if(r1!=0) {
					if(vis[l1[i]]==0) {
						sum+=l1[i];
						vis[h1[l1[i]]]=1;
						r1--;
					}
				} else {
					break;
				}
			}
			for(int i=1; i<=n; i++) {
				if(r2!=0) {
					if(vis[l2[i]]==0) {
						sum+=l2[i];
						vis[h2[l1[i]]]=1;
						r1--;
					}
				} else {
					break;
				}
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
