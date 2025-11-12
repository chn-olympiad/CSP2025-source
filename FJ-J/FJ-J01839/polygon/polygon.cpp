#include<iostream>
#define int long long
using namespace std;
const int MAXN=5e3+10,mod=998244353;
int n,a[MAXN],ans=0,b[25];
bool flag=1;
void dfs(int k,int cnt){
	if(k==n+1){
		if(cnt<3)return;
		int s=0,maxn=-1;
		for(int i=1;i<=n;i++){
			s+=b[i]*a[i];
			if(b[i])maxn=max(maxn,a[i]);
		}
		if(maxn*2<s)ans++;
		return;	
	}
	b[k]=1;
	dfs(k+1,cnt+1);
	b[k]=0;
	dfs(k+1,cnt);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		if(a[i]!=1)flag=0;
	}
	if(flag){
		int sum=1;
		for(int i=1;i<=n;i++)sum=(sum*2)%mod;
		sum-=(n*(n-1)/2+n+1);
		cout<<sum;
	}
	dfs(1,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
