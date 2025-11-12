#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
ll ans;
int t,n;
int a[N][5];
vector<int> v[6];
void init(){
	for(int i=1;i<=3;i++){
		v[i].clear();
	}
	ans=0;
}
void solve(){
	init();
	cin>>n;
	for(int i=1;i<=n;i++){
		int m1=-1,m2=-1,i1=0,i2=0;
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if(a[i][j]>m1){
				m2=m1,i2=i1;
				m1=a[i][j];i1=j;
			}else if(a[i][j]>m2){
				m2=a[i][j],i2=j;
			}
		}
		// cout<<m1<<" "<<i1<<endl;
		v[i1].push_back(m2-m1);
		ans+=m1;
	}
	for(int i=1;i<=3;i++){
		sort(v[i].begin(),v[i].end(),[&](int x,int y){
			return x>y;
		});
		if(v[i].size()<=n/2) continue;
		for(int j=0;j<v[i].size()-(n/2);j++){
			// cout<<j<<endl;
			ans+=v[i][j];
		}
		// cout<<i<<" "<<ans<<endl;
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}