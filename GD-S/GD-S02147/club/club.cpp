#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N],b[N],c[N],x[N<<1],id[N<<1],flag[N],ans,cnt,sum;
//dp[N>>1][N>>1],
inline void run(){
	cin>>n,ans=0,cnt=0,sum=0,fill(flag,flag+N,1);
//	if(n<=200){
//		for(int i=1;i<=n;i++){
//			cin>>a>>b>>c;
//			for(int x=min(n>>1,i);x>=0;x--){
//				for(int y=min(n>>1,i-x),yy=max(0,i-x-(n>>1));y>=yy;y--){
//					if(i-x-y)dp[x][y]+=c;
//					if(x)dp[x][y]=max(dp[x][y],dp[x-1][y]+a);
//					if(y)dp[x][y]=max(dp[x][y],dp[x][y-1]+b);
//				}
//			}
//		}
//		for(int x=n>>1;x>=0;x--)for(int y=n>>1;y>=(n>>1)-x;y--)ans=max(ans,dp[x][y]);
//		for(int x=n>>1;x>=0;x--)for(int y=n>>1;y>=0;y--)dp[x][y]=0;
//		cerr<<ans<<"\n";
//	}
//	else{
//		for(int i=1;i<=n;i++)cin>>a>>b>>c,x[i]=a-b,ans+=b;
//		sort(x+1,x+1+n);
//		for(int i=n/2+1;i<=n;i++)ans+=x[i];
//		cerr<<ans<<"\n";
//	}
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i],x[i*2-1]=a[i]-c[i],x[i*2]=b[i]-c[i],
		id[i*2-1]=i*2-1,id[i*2]=i*2,ans+=c[i],a[i]=0,b[i]=0;
//	cerr<<ans<<"\n";
	sort(id+1,id+1+n*2,[](int a,int b){return x[a]>x[b];});
	while(cnt<n*2&&(sum<n/2||x[id[cnt+1]]>0))cnt++,sum+=flag[(id[cnt]+1)/2],flag[(id[cnt]+1)/2]=0;
	for(int i=1;i<=cnt;i++){
		if(id[i]&1)a[(id[i]+1)/2]=x[id[i]];
		else b[id[i]/2]=x[id[i]];
	}
	for(int i=1;i<=n;i++){
		if(b[i]<0&&a[i]==0)a[i]=b[i];
		if(a[i]<0&&b[i]==0)b[i]=a[i];
		x[i]=a[i]-b[i],id[i]=i,ans+=b[i];
//		cerr<<a[i]<<" "<<b[i]<<"\n";
	}
//	cerr<<ans<<"\n";
	sort(id+1,id+1+n,[](int a,int b){return x[a]>x[b];});
	for(int i=1;i<=n/2;i++){
//		cerr<<x[id[i]]<<" ";
		ans+=x[id[i]];
		if(x[id[i]]<0&&sum-i<=n/2)break;
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;while(t--)run();
	return 0;
}
