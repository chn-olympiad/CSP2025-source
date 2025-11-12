#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int t,n,a[N][5];
int cnt[5],f[N];
void solve(){
	cnt[1]=cnt[2]=cnt[3]=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
	int res=0;
	for(int i=1;i<=n;i++){
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) cnt[1]++,res+=a[i][1],f[i]=1;
		else if(a[i][2]>=a[i][3]&&a[i][2]>=a[i][1]) cnt[2]++,res+=a[i][2],f[i]=2;
		else cnt[3]++,res+=a[i][3],f[i]=3;
	}
	if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
		cout<<res<<"\n";
		return ;
	}
	for(int j=1;j<=3;j++){
		if(cnt[j]>n/2){
			int t=cnt[j]-n/2;
			vector<int>v;
			for(int i=1;i<=n;i++){
				if(f[i]!=j) continue;
				if(j==1) v.push_back(a[i][1]-max(a[i][2],a[i][3]));
				if(j==2) v.push_back(a[i][2]-max(a[i][1],a[i][3]));
				if(j==3) v.push_back(a[i][3]-max(a[i][2],a[i][1]));
			}
			sort(v.begin(),v.end());
			for(int i=0;i<t;i++) res-=v[i];
			cout<<res<<"\n";
			return;
		}
	}
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) solve();
	return 0;
}


