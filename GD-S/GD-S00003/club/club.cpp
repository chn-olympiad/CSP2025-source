#include<bits/stdc++.h>
#define int long long 
using namespace std;
struct h{
	int a,b,c;
}x[500010];
bool cmp(h a,h b){
	return a.a>b.a;
}
int a[500010],b[500010],c[500010],dp[35][35][35][35];
int n,ans;
int f(int x,int a1,int b1,int c1){
	if(dp[x][a1][b1][c1])return dp[x][a1][b1][c1];
	if(x>n)return 0;
	int res=0;
	if(a1<n/2)
	res=f(x+1,a1+1,b1,c1)+a[x];
	if(b1<n/2)
	res=max(res,f(x+1,a1,b1+1,c1)+b[x]);
	if(c1<n/2)
	res=max(res,f(x+1,a1,b1,c1+1)+c[x]);
	dp[x][a1][b1][c1]=res;
	return res;
}
void solve(){
	ans=0;
	memset(dp,0,sizeof(dp));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		x[i]={a[i],b[i],c[i]}; 
	}
	if(n<=30){
		ans=f(1,0,0,0);
		cout<<ans<<'\n';
		return ;
	}
	sort(x+1,x+n+1,cmp);
	int i=1;
	for(i=1;i<=n/2;i++){
		ans+=x[i].a;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
} 
