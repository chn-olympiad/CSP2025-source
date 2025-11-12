#include<bits/stdc++.h>
using namespace std;
const int N=5000+5;
const int mod=998244353;
int n,ans=0;
int C[N][N];
int a[N];
void init(){
	memset(C,0,sizeof(C));
	for(int i=1;i<=5000;i++){
		C[1][i]=1;
		C[2][i]=i-1;
		C[i][i]=1;
	}
	C[1][1]=1;
	for(int i=3;i<=5000;i++){
		for(int j=2;j<=5000;j++){
			C[i][j]=C[i][j-1]+C[i-1][j-1];
		}
	}
	return ;
}
int dfs(int k,int p,int maxn,int mu){
	if(p-1<k-mu) return 0;
	if(k==mu && maxn>=0) return 0;
	if(k==mu && maxn<0) return 1;
	if(maxn<=0) return C[k-mu+1][p];
	int cnt=0;
	for(int i=p-1;i>=k-mu;i--) cnt=(cnt+dfs(k,i,maxn-a[i],mu+1))%mod;
	return cnt%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	init();
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int _=3;_<=n;_++) for(int i=_;i<=n;i++) ans=(ans+dfs(_,i,a[i],1))%mod;
	cout<<ans%mod;
	return 0;
}
