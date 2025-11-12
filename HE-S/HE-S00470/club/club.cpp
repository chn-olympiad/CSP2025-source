#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> v[4];
int T,n,ans,d[200005][4];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int maxid=0,secmax=0;
			for(int j=1;j<=3;j++){
				cin>>d[i][j];
				if(!maxid || d[i][maxid]<d[i][j]){
					secmax=max(secmax,d[i][maxid]);
					maxid=j;
				}else secmax=max(secmax,d[i][j]);
			}
			ans+=d[i][maxid];
			v[maxid].push_back(d[i][maxid]-secmax);
		}
		for(int i=1;i<=3;i++){
			if(v[i].size()>n/2){
				sort(v[i].begin(),v[i].end(),cmp);
				while(v[i].size()>n/2){
					ans-=v[i].back();
					v[i].pop_back();
				}
				break;
			}
		}
		cout<<ans<<'\n';
		ans=0;
		for(int i=1;i<=3;i++) v[i].clear();
	}
	return 0;
}
