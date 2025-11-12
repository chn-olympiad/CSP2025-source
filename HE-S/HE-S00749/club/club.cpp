#include<bits/stdc++.h>
using namespace std;
const int inf=1e5+10;
int n;
pair<int,int> a[inf][4];
int cnt[4];
struct jtr{
	int id,d_1,d_2;
}s[inf];
inline void sol(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j].first;
			a[i][j].second=j;
		}
		sort(a[i]+1,a[i]+1+3);
	}
	for(int i=1;i<=n;i++){
		s[i].id=i;
		s[i].d_1=a[i][3].first-a[i][2].first;
		s[i].d_2=a[i][2].first-a[i][1].first;
	}
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=3;j++){
	// 		cout<<a[i][j].first<<':'<<a[i][j].second<<' ';
	// 	}
	// 	cout<<'\n';
	// }
	int ans=0;
	sort(s+1,s+n+1,[](jtr x,jtr y){return x.d_1==y.d_1?x.d_2>y.d_2:x.d_1>y.d_1;});
	// for(int i=1;i<=n;i++){
	// 	cout<<s[i].id<<' '<<s[i].d_1<<' '<<s[i].d_2<<'\n';
	// }
	for(int i=1;i<=n;i++){
		int o=s[i].id;
		for(int j=3;j>=1;j--){
			if(cnt[a[o][j].second]>=(n/2)){
				continue;
			}
			else{
				cnt[a[o][j].second]++;
				ans+=a[o][j].first;
				break;
			}
		}
		// cout<<ans<<'\n';
	}
	cout<<ans<<'\n';
	memset(a,0,sizeof a);
	memset(cnt,0,sizeof cnt);
	memset(s,0,sizeof s);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) sol();
}