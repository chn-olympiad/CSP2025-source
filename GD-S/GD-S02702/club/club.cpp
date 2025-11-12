#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n; cin>>n;
	vector<vector<int>> a(n+1,vector<int>(4,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	int cnt1=0,cnt2=0,cnt3=0;
	int ans=0;
	vector<int> vec1,vec2,vec3;
	for(int i=1;i<=n;i++){
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			cnt1++; ans+=a[i][1];
			vec1.push_back(min(a[i][1]-a[i][2],a[i][1]-a[i][3]));
		}
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
			cnt2++; ans+=a[i][2];
			vec2.push_back(min(a[i][2]-a[i][1],a[i][2]-a[i][3]));
		}
		else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
			cnt3++; ans+=a[i][3];
			vec3.push_back(min(a[i][3]-a[i][1],a[i][3]-a[i][2]));
		}
	}
	sort(vec1.begin(),vec1.end());
	sort(vec2.begin(),vec2.end());
	sort(vec3.begin(),vec3.end());
	if(cnt1>n/2){
		for(int i=0;i<cnt1-n/2;i++) ans-=vec1[i];
	}
	else if(cnt2>n/2){
		for(int i=0;i<cnt2-n/2;i++) ans-=vec2[i];
	}
	else if(cnt3>n/2){
		for(int i=0;i<cnt3-n/2;i++) ans-=vec3[i];
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
