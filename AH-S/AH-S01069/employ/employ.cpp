#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[505],n,m,cnt,ans[505];
string s;
void dfs(ll cur,ll fil){
	if(cur>m){
		cnt++;
		cnt%=998244353;
		return ;
	}
	for(ll i=ans[cur-1]+1;i<=n;i++){
		ans[cur]=i;
		if(s[i-1]=='0'){
			 if(a[i]>=fil+1) dfs(cur+1,fil+1);
		} 
		else dfs(cur+1,fil);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	
	cin>>s;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0);
	cout<<cnt;
	return 0;
}
