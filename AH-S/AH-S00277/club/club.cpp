#include<bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int,int>
#define ALL(x) x.begin(),x.end()
using namespace std;
const int MOD1=1e9+7,MOD2=998244353;
const int MOD=MOD1;
const int INF=1e18;
const int N=100005;
int n;
int a[N][4];
void solve_(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	int ans=0;
	vector<int> vec[4];
	for(int i=1;i<=n;i++){
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			ans+=a[i][1];
			vec[1].push_back(a[i][1]-max(a[i][2],a[i][3]));
		}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
			ans+=a[i][2];
			vec[2].push_back(a[i][2]-max(a[i][1],a[i][3]));
		}else{
			ans+=a[i][3];
			vec[3].push_back(a[i][3]-max(a[i][1],a[i][2]));
		}
	}
	if(vec[1].size()>n/2){
		sort(ALL(vec[1]));
		for(int i=0;i<vec[1].size()-n/2;i++){
			ans-=vec[1][i];
		}
	}else if(vec[2].size()>n/2){
		sort(ALL(vec[2]));
		for(int i=0;i<vec[2].size()-n/2;i++){
			ans-=vec[2][i];
		}
	}else if(vec[3].size()>n/2){
		sort(ALL(vec[3]));
		for(int i=0;i<vec[3].size()-n/2;i++){
			ans-=vec[3][i];
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int testcase=1,multitest=1;
	if(multitest)cin>>testcase;
	while(testcase--){
		solve_();
	}
	return 0;
}
