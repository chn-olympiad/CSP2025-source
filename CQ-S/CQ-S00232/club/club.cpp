#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][4];
vector<int>g[4];
void solve(){
	cin>>n;
	int ans=0,mp[N]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int maxn=max(a[i][1],max(a[i][2],a[i][3]));
		if(a[i][1]==maxn)
			g[1].push_back(i);
		else if(a[i][2]==maxn)
			g[2].push_back(i);
		else
			g[3].push_back(i);
		ans+=maxn;
	}
	int cnt=0; 
	for(int i=1;i<=3;i++){
		if(g[i].size()>n/2){
			for(auto f:g[i]){
				cnt=g[i].size()-n/2;
				int maxn=max(a[f][1],max(a[f][2],a[f][3]));
				if(maxn==a[f][1])
					mp[maxn-max(a[f][2],a[f][3])]++;
				else if(maxn==a[f][2])
					mp[maxn-max(a[f][1],a[f][3])]++;
				else if(maxn==a[f][3])
					mp[maxn-max(a[f][1],a[f][2])]++;
			}
			break;
		}
	}
//	cout<<cnt<<endl;
	for(int i=1;i<N;i++){
		if(mp[i]){
//			cout<<i<<endl;
			if(mp[i]>=cnt){
				ans-=cnt*i;
				break;
			}
//		cout<<mp[i]<<endl;
			cnt-=mp[i];
			ans-=i*mp[i];
		}
		
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		g[1].clear();
		g[2].clear();
		g[3].clear();
		solve();
	}
	return 0;
}
