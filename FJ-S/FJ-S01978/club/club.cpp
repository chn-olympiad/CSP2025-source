#include<bits/stdc++.h>

using namespace std;

long long T,n,A[100005][3],cnt[3],ans,flag[100005],tot,p[100005];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n,cnt[0]=cnt[1]=cnt[2]=ans=tot=0;
		for(int i=1;i<=n;i++) cin>>A[i][0]>>A[i][1]>>A[i][2];
		for(int i=1;i<=n;i++) {
			if(A[i][0]>=A[i][1]&&A[i][0]>=A[i][2]) ans+=A[i][0],cnt[0]++,flag[i]=0;
			else if(A[i][1]>=A[i][0]&&A[i][1]>=A[i][2]) ans+=A[i][1],cnt[1]++,flag[i]=1;
			else ans+=A[i][2],cnt[2]++,flag[i]=2;
		}
		if(cnt[0]>n/2) {
			for(int i=1;i<=n;i++) if(flag[i]==0) p[++tot]=min(A[i][0]-A[i][1],A[i][0]-A[i][2]);
			sort(p+1,p+tot+1);
			for(int i=1;i<=cnt[0]-n/2;i++) ans-=p[i];
		}
		if(cnt[1]>n/2) {
			for(int i=1;i<=n;i++) if(flag[i]==1) p[++tot]=min(A[i][1]-A[i][0],A[i][1]-A[i][2]);
			sort(p+1,p+tot+1);
			for(int i=1;i<=cnt[1]-n/2;i++) ans-=p[i];
		}
		if(cnt[2]>n/2) {
			for(int i=1;i<=n;i++) if(flag[i]==2) p[++tot]=min(A[i][2]-A[i][0],A[i][2]-A[i][1]);
			sort(p+1,p+tot+1);
			for(int i=1;i<=cnt[2]-n/2;i++) ans-=p[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
