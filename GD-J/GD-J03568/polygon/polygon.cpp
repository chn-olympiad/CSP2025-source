#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5005;
int n,a[MAXN],ans;
map<string,bool> vis;
void dfs(int x,int cnt,int m,int k,string s){
	if(x>n){
		if(cnt>2*m&&k>=3&&vis[s]==0){
			ans++;
			vis[s]=1;
		}
		return ;
	}
	if(x+1!=n+1){
		dfs(x+1,cnt+a[x+1],max(m,a[x+1]),k+1,s+char('0'+x+1));
	}else{
		dfs(x+1,cnt+a[x+1],max(m,a[x+1]),k+1,s);
	}
	dfs(x+1,cnt,m,k,s);
	return ;
}
int ac(int x,int y){
	int q1=1,q2=1,q3=1;
	for(int i=y+1;i<=x;i++){
		q1*=i;
	}
	for(int i=2;i<=x-y;i++) q3*=i;
	return q1/q3;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	int ma=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(ma==1){
		for(int i=3;i<=n;i++){
			ans+=ac(n,i);
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	dfs(0,0,0,0,"");
	cout<<(ans)%998244353;
	return 0;
} 
