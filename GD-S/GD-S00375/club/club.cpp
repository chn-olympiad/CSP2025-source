#include<iostream>
using namespace std;
using ll=long long;
int n,c[100005][3];
ll ans;
void dfs(int dep,int s_1,int s_2,int s_3,ll sum){
	if(s_1>n/2||s_2>n/2||s_3>n/2)return;
	if(dep==n+1){
		ans=max(ans,sum);
		return;
	}
	dfs(dep+1,s_1+1,s_2,s_3,sum+c[dep][0]);
	dfs(dep+1,s_1,s_2+1,s_3,sum+c[dep][1]);
	dfs(dep+1,s_1,s_2,s_3+1,sum+c[dep][2]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++)cin>>c[i][0]>>c[i][1]>>c[i][2];
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
