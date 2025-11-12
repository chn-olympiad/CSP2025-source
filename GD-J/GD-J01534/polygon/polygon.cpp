#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10,Mod=998244353;
int a[N],n,maxxx=-1,ans;
void dfs(int dep,int maxx,int num,int cnt){
	if(dep==n+1) {
		if(cnt<3) return ;
		if(maxx*2>=num) return ;
		ans=(ans+1)%Mod;
//		cout<<maxx<<" "<<num<<" "<<cnt<<endl;
		return;
	} 
//	cout<<dep<<" "<<maxx<<" "<<num<<" "<<cnt<<endl; 
	dfs(dep+1,max(maxx,a[dep]),num+a[dep],cnt+1);
	dfs(dep+1,maxx,num,cnt);
}
int c[5001][5001];
void init(){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++) {
			if(i==0 || j==0) c[i][j]=1;
			else c[i][j]=(c[i-1][j]+c[i-1][j-1])%Mod;
		}
	}
}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i],maxxx=max(maxxx,a[i]);
	if(n<=20) {
		dfs(1,0,0,0);
		cout<<ans<<endl;
		return 0;
	}
	ans=0;
	if(maxxx<=1){
		init();
		for(int i=3;i<=n;i++) ans=(ans+c[n][i])%Mod;
		cout<<ans<<endl;
		return 0;
	}
	cout<<ans;
	return 0;
}
/*
当 $n \le 20$ 时，$2^n$可过,拿40分    1~10
当 $a[i] \le 1$时，组合数，24分       15~20
预计64分 


    
不是道水题吧（提高）……       应该没有人人AC 
*/
