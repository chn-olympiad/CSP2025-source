#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 100005
int t,n;
int a[N][3];
vector<int>st[3];
int ans;
void clr(){
	ans=0;
	for(int i=0;i<3;i++)st[i].clear();
}
void sol(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			if(a[i][j]>=a[i][(j+1)%3]&&a[i][j]>=a[i][(j+2)%3]){
				ans+=a[i][j];
				st[j].push_back(a[i][j]-max(a[i][(j+1)%3],a[i][(j+2)%3]));
				break;
			}
		}
	}
	for(int o=0;o<3;o++){
		if(st[o].size()<=(n/2))continue;
		auto b=st[o];
		sort(b.begin(),b.end());
		int cnt=b.size()-(n/2);
		for(int i=0;i<cnt;i++)ans-=b[i]; 
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)clr(),sol();
	return 0;
} 
