#include<bits/stdc++.h>
using namespace std;
#define int long long
//           dp i,j 处理到 i 选第 j 个社团的答案
int n,cnt[6],dp[100005][3],a[100005][3],ans;
void dfs(int x,int cost){
	if(x>n){
		ans=max(ans,cost);
		return ;
	}
	if(cnt[1]){
		cnt[1]--,dfs(x+1,cost+a[x][1]),cnt[1]++;
	}if(cnt[2]){
		cnt[2]--,dfs(x+1,cost+a[x][2]),cnt[2]++;
	}if(cnt[3]){
		cnt[3]--,dfs(x+1,cost+a[x][3]),cnt[3]++;
	}
}
vector<int> tmp;
pair<int,int> tmpp[1100000];
bool cmp(pair<int,int> x,pair<int,int> y){
	return x.first+y.second>x.second+y.first;
}
void solve(){
	cin>>n;ans=0;
	bool i2=1,i3=0;
	for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3],i2=(a[i][2]?0:i2),i3=(a[i][3]?0:i3);
	for(int i=1;i<=3;i++)cnt[i]=n/2;
	if(n<=10){
		dfs(1,0);
		cout<<ans<<"\n";
		return ;
	}
	if(i2&&i3){
		tmp.clear();
		for(int i=1;i<=n;i++)tmp.push_back(a[i][1]);
		sort(tmp.begin(),tmp.end(),greater<int>());
		int ans=0;
		for(int i=0;i<n/2;i++)ans+=a[i][1];
		cout<<ans<<"\n";
	}
	int tot=0;
	for(int i=1;i<=n;i++)tmpp[++tot]={a[i][1],a[i][2]};
	sort(tmpp+1,tmpp+tot+1,cmp);
	for(int i=1;i<=n/2;i++)ans+=tmpp[i].first;
	for(int i=n/2+1;i<=n;i++)ans+=tmpp[i].second;
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
