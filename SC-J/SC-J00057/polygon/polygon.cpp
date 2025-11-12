#include<bits/stdc++.h>
#define int long long
const int mod=998244353;
using namespace std;
int n,ans;
int a[200005];
void dfs(int now,int mx,int sum){
	if(now>n){
		if(mx==-1e5)return;
		if(sum>mx*2){
			ans++;
			ans%=mod;
		}
		return;
	}
	dfs(now+1,max(mx,a[now]),sum+a[now]);
	dfs(now+1,mx,sum);
	return;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1,-1e5,0);
		cout<<ans<<endl;	
	}else{
		int cc=0;
		vector<int>e;
		for(int i=3;i<=n;i++){
			e.clear();
			int cnt=i;
			if(i>n/2){
				cnt=n-i;
			}
			for(int j=n;j>=n-cnt+1;j--){
				e.push_back(j);
			}
			for(int j=2;j<=((i>n/2)?n-i:i);j++){
				int cnt=j;
				for(int k=0;k<(int)e.size();k++){
					if(cnt==1)break;
					int x=__gcd(cnt,e[k]);
					cnt/=x,e[k]/=x;
				}
			}
			int num=1;
			for(auto u:e){
				num*=u;
				num%=mod;
			}
			cc+=num;
			cc%=mod;
		}
		cout<<cc<<endl;
	}
	return 0;
}