#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[100005][3],b[100005],c[100005],cnt[3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)for(int j=0;j<3;j++)cin>>a[i][j];
		memset(cnt,0,sizeof cnt);
		int ans=0;
		for(int i=1;i<=n;i++){
			int mx=-1,pos=0;
			for(int j=0;j<3;j++)if(mx<a[i][j])mx=a[i][j],pos=j;
			b[i]=pos,cnt[pos]++,ans+=mx;
		}
		if(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2){cout<<ans<<"\n";continue;}
		int xx=0,cc=0;if(cnt[0]>n/2)xx=0;else if(cnt[1]>n/2)xx=1;else if(cnt[2]>n/2)xx=2;
		for(int i=1;i<=n;i++)if(b[i]==xx){
			int mx=-1,pos=0;
			for(int j=0;j<3;j++)if(j!=b[i]&&mx<a[i][j])mx=a[i][j],pos=j;
			c[++cc]=a[i][b[i]]-mx;
		}
		sort(c+1,c+cc+1);
		for(int i=1;i<=cnt[xx]-n/2;i++)ans-=c[i];cout<<ans<<"\n";
	}
} 
