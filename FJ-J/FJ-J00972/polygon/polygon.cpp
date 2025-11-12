#include<bits/stdc++.h>
using namespace std;
const int N=5e3+3,mod=998244353;
int n,a[N],s[N];
long long f[N][N],ans;
bool flag;
//bool cmp(int x,int y){
//	return x>y;
//}
void dfs(int idx,int maxn,int sum,int cnt){
//	cout<<idx<<' '<<maxn<<' '<<sum<<' '<<cnt<<' '<<ans<<endl;
	if(cnt>=1&&sum>a[maxn]){
		ans++;
		ans%=mod;
	}
	for(int i=idx-1;i>=1;i--){
		dfs(i,maxn,sum+a[i],cnt+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}
//		s[i]=s[i-1]+a[i];
	}
	if(!flag){
		for(int j=1;j<=n;j++){
			f[1][j]=j;
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=(1LL*(f[i-1][j-1]+f[i][j-1])%mod);
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<f[i][j]<<' ';
//			}
//			cout<<endl;
//		}
		for(int i=3;i<=n;i++){
			ans=(ans+f[i][n])%mod;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		dfs(i,i,0,0);
	}
	cout<<ans;
	return 0;
}
