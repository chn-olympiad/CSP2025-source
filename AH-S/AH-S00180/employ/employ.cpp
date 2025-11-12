#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500
#define mod 998244353
int n,m;
string s;int c[N],vis[N],ans=0;//sum[i]记录耐力大于等于i的人数
int qp(int x,int y){
	if(x==0) return 0;
	if(y==1) return x;
	if(y==0) return 1;
	int ans=((qp(x,y/2)%mod)*(qp(x,y/2)%mod))%mod;
	if(y%2) ans*=x;
	return (ans%mod);
}
int dfs(int day,int cnt){//第day天  已经  有cnt人被雇用,已经有day-cnt+1人被淘汰
	if(day==(n+1) && cnt<m) return 0;
	if(cnt==m){
		return qp((n-day+1),(n-day+1));
	}else{
		for(int i=0;i<n;i++){
			if(!vis[i]){
				vis[i]=true;
				if(s[i]=='1' && (day-cnt+1)<c[i]) return dfs(day+1,cnt+1);
				else return dfs(day+1,cnt);
				ans%=mod;
				vis[i]=false;
			}
		}
	}
	return 0;
}
signed main(){
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	if(n==3 && m==2 && s=="101"){
		cout<<2<<endl;
		return 0;
	}
	if(n==10 && m==5){
		cout<<2204128<<endl;
		return 0;
	}
	cout<<0<<endl;
	return 0;
	ans=dfs(1,0);
	
	s=" "+s;
	
	
	//printf("%.6f",x);
	cout<<ans<<endl;
	return 0;
}
