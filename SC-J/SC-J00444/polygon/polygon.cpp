#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
int num[5005];
int n;
set<int>se;
int ans=0;
bool judge(vector<int> ve){
	int mx=-1;
	int sum=0;
	for(int num:ve){
//		cout<<num<<' ';
		mx=max(mx,num);
		sum+=num;
	}
//	cout<<'\n';
	return (ve.size()>=3)&&(sum>(2*mx));
}
void dfs(vector<int> ve,int nw){
	if(nw>n) return ;
	dfs(ve,nw+1);
	ve.push_back(num[nw]);
	if(judge(ve)){
		ans++;
		ans%=MOD;
	}
	dfs(ve,nw+1);
}
bool solve(){
	vector<int> ve;
	dfs(ve,1);
}
int solve1(int n){
	int mu=1+n+(n*(n-1))/2;
//	cout<<mu<<" ";
	int tot=1;
	for(int i=1;i<=n;i++){
		tot*=2;
		tot%=MOD;
	}
	tot=(tot-mu+MOD)%MOD;
	return tot;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int mx=-1;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		mx=max(num[i],mx);
	}
	if(mx==1){
		cout<<solve1(n);
	}
	solve();
	cout<<ans;
	
	
	
	
//	int n;
//	cin>>n;
//	cout<<solve1(n);
	return 0;
}