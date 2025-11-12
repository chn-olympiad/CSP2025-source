#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


int n;
int a[200010][4];
int b[200010];
int c[200010];


int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
		int cnt0=0,cnt1=0,cnt2=0;LL ans=0;
		for(int i=1;i<=n;i++){
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) ans+=a[i][0],cnt0++,b[i]=0;
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]) ans+=a[i][1],cnt1++,b[i]=1;
			else ans+=a[i][2],cnt2++,b[i]=2;
		}
		int tt=-1,cnt=0,mx=max(max(cnt0,cnt1),cnt2);
		if(cnt0>n/2) tt=0;
		if(cnt1>n/2) tt=1;
		if(cnt2>n/2) tt=2;
		if(tt==-1){cout<<ans<<"\n";continue;}
		for(int i=1;i<=n;i++){
			if(b[i]==tt){
				cnt++,c[cnt]=a[i][tt];
				if(tt==0) c[cnt]-=max(a[i][1],a[i][2]);
				if(tt==1) c[cnt]-=max(a[i][0],a[i][2]);
				if(tt==2) c[cnt]-=max(a[i][0],a[i][1]);
			}
		}
		sort(c+1,c+cnt+1);
		for(int i=1;i<=mx-n/2;i++) ans-=c[i];
		cout<<ans<<"\n";
	}
	return 0;
}
