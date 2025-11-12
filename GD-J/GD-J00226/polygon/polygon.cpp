#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5005],maxx=0;
int ans=0;
int C[5005][5005];
void dfs(const int &now_choose,const int &choosed,const int &choosed_len,const int &choosed_max){
	if(now_choose>n){
		if((choosed>=3)&&(choosed_len>(choosed_max*2))) ++ans;
		return;
	}
	dfs(now_choose+1,choosed,choosed_len,choosed_max);
	dfs(now_choose+1,choosed+1,choosed_len+a[now_choose],max(choosed_max,a[now_choose]));
}
void solve1(){
	dfs(1,0,0,0);
	cout<<ans;
}
void solve2(){
	int ans=0;
	for(int m=3;m<=n;++m)
		ans=(ans+C[n][m])%mod;
	cout<<ans;
}
void _init_1_(){
	for(int i=0;i<=n;++i)
		C[i][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
}
int f[5005][5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	_init_1_();
	for(int i=1;i<=n;++i)
		cin>>a[i],maxx=max(maxx,a[i]);
	if(n<=20){
		solve1();
		return 0;
	}
	if(maxx==1){
		solve2();
		return 0;
	}
	stable_sort(a+1,a+n+1);
	int ans=0;
	for(int i=0;i<a[1];++i)
		f[1][i]=1;
	for(int i=1;i<=n;++i){
		for(int j=2;j<i;++j)
			ans=(ans+f[j-1][a[i]-a[j]])%mod;
		for(int j=0;j<=5000;++j)
			f[i+1][min(5000,j+a[i])]+=f[i][j];
		for(int j=0;j<=5000;++j)
			f[i+1][j]+=f[i][j];
	}
	cout<<ans;
	return 0;
}
