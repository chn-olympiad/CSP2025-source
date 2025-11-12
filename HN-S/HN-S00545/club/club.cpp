#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+7;
ll n,m,t,a[N][5],ans; 
int cnt[5];
void dfs(int id,ll val){
	if(id==n+1){
		ans=max(ans,val);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]<m){
			cnt[i]++;
			dfs(id+1,val+a[id][i]);
			cnt[i]--;
		}	
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		m=n>>1;
		ans=0;
		ll A=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}A+=(a[i][2]+a[i][3]);
		}
		if(A==0){
			vector<int>A;
			for(int i=1;i<=n;i++){
				A.push_back(a[i][1]);
			}
			sort(A.begin(),A.end());
			for(int i=n/2;i<=n-1;i++){
				ans+=A[i];
			}cout<<ans<<'\n';
			continue;
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
