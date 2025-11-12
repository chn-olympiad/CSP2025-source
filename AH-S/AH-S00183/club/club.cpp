#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][3],t[N];
int p0[N],p1[N],p2[N];
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T; cin>>T;
    while(T--) {
	    int n; cin>>n;
	    int cnt0=0,cnt1=0,cnt2=0,ans=0;
	    for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
	    for(int i=1;i<=n;i++) {
		    int maxn=max(a[i][0],max(a[i][1],a[i][2]));
		    if(maxn==a[i][0]) p0[++cnt0]=i;
		    if(maxn==a[i][1]) p1[++cnt1]=i;
		    if(maxn==a[i][2]) p2[++cnt2]=i;
		    ans+=maxn;	
		}	
		if(cnt0>n/2) {
		    for(int i=1;i<=cnt0;i++) {
			    t[i]=a[p0[i]][0]-max(a[p0[i]][1],a[p0[i]][2]);
			}	
			sort(t+1,t+cnt0+1);
			for(int i=1;i<=cnt0-n/2;i++) ans-=t[i];
		}
		if(cnt1>n/2) {
			for(int i=1;i<=cnt1;i++) {
			    t[i]=a[p1[i]][1]-max(a[p1[i]][0],a[p1[i]][2]);
			}	
			sort(t+1,t+cnt1+1);
			for(int i=1;i<=cnt1-n/2;i++) ans-=t[i];
		}
		if(cnt2>n/2) {
			for(int i=1;i<=cnt2;i++) {
			    t[i]=a[p2[i]][2]-max(a[p2[i]][0],a[p2[i]][1]);
			}	
			sort(t+1,t+cnt2+1);
			for(int i=1;i<=cnt2-n/2;i++) ans-=t[i];
		}
		cout<<ans<<"\n";
	}
    return 0;
}
