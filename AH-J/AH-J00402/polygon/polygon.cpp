#include <bits/stdc++.h>
using namespace std;
int a[5005],dp[5005][5005];
long long ans;
map<string,int> mp;
void dfs(int i,int n,int sum,int tmp,int v,string s){
	if(n-i+1<3-v){
		return ;
	}
	if(sum>tmp*2&&v>=3){
		if(mp.find(s)==mp.end()){
			ans++;
			ans%=998244353;
			mp[s]=1;
		}
	}
	if(i>n){
		return ;
	}
	dfs(i+1,n,sum+a[i],a[i],v+1,s+(char)(i+'0'));
	dfs(i+1,n,sum,tmp,v,s);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(1,n,0,0,0,"");
	cout<<ans;
	return 0;
}
