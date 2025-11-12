#include<iostream>
#include<cstdio>
using namespace std;
int mod=998244353;
int n,m;
char s;
int a[520];
int c[520];
int vis[520];
long long ans;
long long jie(int j){
	if(j==1||j==0){
		return 1;
	}
	return jie(j-1)*j;
}
void dfs(int t,int l,int k){
	if(k==m){
		ans=(ans+jie(n-t))%mod;
		return ;
	}
	if(n-t+l<m||t==n){
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){;
			vis[i]=1;
			if(a[t+1]==0||l>=c[i]){
				dfs(t+1,l+1,k);
			}
			if(l<c[i]&&a[t+1]==1){
				dfs(t+1,l,k+1);
			}
			vis[i]=0;
		}
	}
	return ;
}
int f=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(s=='1'){
			a[i]=1;
			f++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(f==n){
		ans=1;
		for(int i=2;i<=n;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans<<endl;
		return 0;
	}
	dfs(0,0,0);
	cout<<ans%mod<<endl;
	return 0;
}
