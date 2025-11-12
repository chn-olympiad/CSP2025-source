#include<bits/stdc++.h>
using namespace std;
long long const mod=998244353;
int a[5005];
long long f[5001][5005];
long long ans=0;
void dfs(int x,int n,int num,int cnt){
	if(num>a[n+1])return;
	if(x>n){
		if(cnt<2){
			return;
		}
		ans++;
		return;
	}
	dfs(x+1,n,num+a[x],cnt+1);
	dfs(x+1,n,num,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[n]==1){
		long long an=2;
		long long num=0;
		for(int i=3;i<=n;++i){
			an*=2;
			an%=mod;
			num+=an+mod-1-(i-1);
			num%=mod;
		} 
		cout<<num;
		return 0;
	}
	else if(n<=20){
		long long an=2;
		long long num=0;
		for(int i=3;i<=n;++i){
			an*=2;
			an%=mod;
			ans=0;
			dfs(1,i-1,0,0);
			num+=an+mod-1-ans-(i-1);
			num%=mod;
		} 
		cout<<num;
	}
	else{
		for(int i=1;i<=n;++i){
			f[i-1][0]=1;
			for(int j=1;j<=5000;++j){
				if(j-a[i]>=0)
				f[i][j]=f[i-1][j-a[i]];
				f[i][j]+=f[i-1][j];
				f[i][j]%=mod;
			}
			f[i][5001]=f[i-1][5001];
			f[i][5001]*=2;
			f[i][5001]%=mod;
			for(int j=5000-a[i]+1;j<=5000;++j){
				f[i][5001]+=f[i][j];
				f[i][5001]%=mod;
			}
		}
		long long ans=0;
		for(int i=3;i<=n;++i){
			for(int j=a[i]+1;j<=5001;++j){
				ans+=f[i-1][j];
				ans%=mod;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
