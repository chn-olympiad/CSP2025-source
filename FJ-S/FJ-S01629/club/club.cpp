#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+25;
ll T,n,a[N][3],ans;
vector<ll> num[3],v;
void work(int x,int y,int z){
	v.clear();
	for(int i:num[x]){
		ll mx=max(a[i][y],a[i][z]);
		v.push_back(a[i][x]-mx);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<num[x].size()-n/2;i++){
		ans-=v[i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=0;i<3;i++) num[i].clear();
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];	
			}
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				num[0].push_back(i);
				ans+=a[i][0];
			} 
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				num[1].push_back(i);
				ans+=a[i][1];
			}
			else if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1]){
				num[2].push_back(i);
				ans+=a[i][2];
			}
		}
		if(num[0].size()>n/2) work(0,1,2);
		else if(num[1].size()>n/2) work(1,0,2);
		else if(num[2].size()>n/2) work(2,0,1);
 		cout<<ans<<"\n";
	}
	return 0;
}