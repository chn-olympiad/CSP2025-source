#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+5;
int n,a[maxn][4],cnt[4],ans,b[maxn],tot;
void init(){
	for(int i=1;i<=n;i++)b[i]=0;
	for(int i=1;i<=3;i++)cnt[i]=0;
	tot=ans=0;
}
void get(int x){
	for(int i=1;i<=n;i++){
		if(a[i][x]>=a[i][1]&&a[i][x]>=a[i][2]&&a[i][x]>=a[i][3]){
			if(x==1)b[++tot]=a[i][x]-max(a[i][2],a[i][3]);
			if(x==2)b[++tot]=a[i][x]-max(a[i][1],a[i][3]);
			if(x==3)b[++tot]=a[i][x]-max(a[i][2],a[i][1]);
		}
	}
	sort(b+1,b+tot+1);
	for(int i=1;i<=tot-(n/2);i++){
		ans-=b[i];
	}
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)cin>>a[i][j];
	init();
	for(int i=1;i<=n;i++){
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			ans+=a[i][1];
			cnt[1]++;
		}
		else if(a[i][2]>=a[i][3]){
			ans+=a[i][2];
			cnt[2]++;
		}
		else{
			ans+=a[i][3];
			cnt[3]++;
		}
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]>n/2)get(i);
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}

