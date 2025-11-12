#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][4],ans=-1;
void dfs(long long sum,long long tot,int cnt,int cntt,int cnttt){
	if(tot==n){
		ans=max(sum,ans);
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1&&cnt+1<=n/2){
			sum+=a[++tot][1];
			cnt++;
			dfs(sum,tot,cnt,cntt,cnttt);
			cnt--;
			sum-=a[tot][1];
			tot--;
		}else if(i==2&&cntt+1<=n/2){
			sum+=a[++tot][2];
			cntt++;
			dfs(sum,tot,cnt,cntt,cnttt);
			cntt--;
			sum-=a[tot][2];
			tot--;
		}else if(i==3&&cnttt+1<=n/2){
			sum+=a[++tot][3];
			cnttt++;
			dfs(sum,tot,cnt,cntt,cnttt);
			cnttt--;
			sum-=a[tot][3];
			tot--;
		}
	}
	return ;
}
int main() {
//	freopen("club2.in","r",stdin);
//	freopen("club2.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n!=2) {
			dfs(0,0,0,0,0);
			cout<<ans<<"\n";
			ans=-1;
		} else {
			int maxx=max(a[1][1]+a[2][2],a[1][1]+a[2][3]);
			int maxxx=max(a[1][3]+a[2][1],a[1][3]+a[2][2]);
			int maxxxx=max(a[1][2]+a[2][1],a[1][2]+a[2][3]);
			maxx=max(maxx,maxxx);
			maxx=max(maxx,maxxxx);
			cout<<max(maxx,maxxxx)<<'\n';
		}
	}
	return 0;
}
