#include <bits/stdc++.h>
using namespace std;
int t,n,maxn,cnt,cnt1,cnt2,cnt3,ans;
int a1[100005],a2[100005],a3[100005],a[100005];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=0; i<n; i++) {
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		ans=0;
		cnt=cnt1=cnt2=cnt3=0;
		for(int i=0; i<n; i++) {
			if(cnt<=n) {
				if(cnt1>n/2&&cnt2<=n/2&&cnt3<=n/2) {
					a[i]=max(a2[i],a3[i]);
				} else if(cnt1>n/2&&cnt2>n/2&&cnt3<=n/2) {
					a[i]=a3[i];
				} else if(cnt1>n/2&&cnt2>n/2&&cnt3>n/2) {
					continue;
				} else if(cnt1<=n/2&&cnt2<=n/2&&cnt3>n/2) {
					a[i]=max(a1[i],a2[i]);
				} else if(cnt1<=n/2&&cnt2>n/2&&cnt3<=n/2) {
					a[i]=max(a1[i],a3[i]);
				} else if(cnt1<=n/2&&cnt2>n/2&&cnt3>n/2) {
					a[i]=a1[i];
				} else if(cnt1>n/2&&cnt2<=n/2&&cnt3>n/2) {
					a[i]=a2[i];
				} else if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2) {
					a[i]=max(a1[i],max(a2[i],a3[i]));
				}
				if(a[i]==a1[i]) {
					cnt1++;
				} else if(a[i]==a2[i]) {
					cnt2++;
				} else if(a[i]==a3[i]) {
					cnt3++;
				}
				cnt=cnt1+cnt2+cnt3;
				ans+=a[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
