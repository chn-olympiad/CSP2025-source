#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int t,n;
int a1[maxn],a2[maxn],a3[maxn],b1[maxn],b2[maxn],b3[maxn],newa1[maxn],newa2[maxn],a11[maxn];
int main() {
	freopen("club.in.txt","r",stdin);
	freopen("club.out.txt","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		bool isorno=0,nooris=0;
		for(int i=0; i<n; i++) {
			cin>>a1[i]>>a2[i]>>a3[i];
			b1[a1[i]]=i;
			b2[a2[i]]=i;
			b3[a2[i]]=i;
			a11[i]=a1[i];
			if(a2[i]||a3[i]) {
				isorno=1;
			}
			if(a3[i]) {
				nooris=1;
			}
		}
		if(!isorno) {
			sort(a1,a1+n);
			int ans=0;
			for(int i=n/2; i<n; i++) {
				ans+=a1[i];
			}
			cout<<ans<<'\n';
			return 0;
		}
		if(!nooris) {
			sort(a11,a11+n);
			for(int i=0; i<n; i++) {
				newa2[b1[a11[i]]]=a2[b1[a11[i]]];
			}
			sort(a2,a2+n);
			for(int i=0; i<n; i++) {
				newa1[b2[a2[i]]]=a1[b2[a2[i]]];
			}
			int ans1=0,ans2=0,cnt11=2,cnt12=2,cnt21=2,cnt22=2;
			for(int i=0; i<n; i++) {
				if(a11[i]>=newa2[i]) {
					if(cnt11) {
						ans1+=a11[i];
						cnt11--;
					} else {
						ans1+=newa2[i];
						cnt12--;
					}
				} else if(a11[i]<newa2[i]) {
					if(cnt12) {
						ans1+=newa2[i];
						cnt12--;
					} else {
						ans1+=a11[i];
						cnt11--;
					}
				}
			}
			for(int i=0; i<n; i++) {
				if(a2[i]>=newa1[i]) {
					if(cnt21) {
						ans2+=a2[i];
						cnt21--;
					} else {
						ans2+=newa1[i];
						cnt22--;
					}
				} else if(a2[i]<newa1[i]) {
					if(cnt22) {
						ans2+=newa1[i];
						cnt22--;
					} else {
						ans2+=a2[i];
						cnt21--;
					}
				}
			}
			cout<<max(ans1,ans2)<<'\n';
		}
	}
	return 0;
}
