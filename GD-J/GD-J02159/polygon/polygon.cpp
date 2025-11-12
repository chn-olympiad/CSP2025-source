#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[5555];
int ans;
int memo[5555];
void dfs(int pos,int sum,int maxn,int cnt,string s){
	if(pos==n+1){
//		cout<<s<<endl;
		if(maxn*2<sum&&cnt>=3) ans++;
		return;
	}
	dfs(pos+1,sum+a[pos],a[pos],cnt+1,s+"1");
	dfs(pos+1,sum,maxn,cnt,s+"0");
} 
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	dfs(1,0,0,0,"");
	cout<<ans%998244353;
	return 0; 
}

