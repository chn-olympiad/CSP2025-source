#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int a[N];
int res[N];
long long ans;
int n;
const int mod=998244353;
void dfs(int s){
	if(s==n+1){
		int cnt=0;
		int maxn=-1;
		int sum=0;
		for(int i=1;i<=n;i++){
			if(res[i]==1){
				cnt++;
				sum+=a[i];
				maxn=max(maxn,a[i]);
			}
		}
		if(cnt>=3&&sum>maxn*2){
			ans++;
		}
		return;	
	}
	res[s]=0;
	dfs(s+1);
	res[s]=1;
	dfs(s+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20)dfs(1);
	else{
		for(int i=3;i<=n;i++){
			long long tmp=1;
			for(int j=n;j>i;j--){
				tmp=(tmp*j)%mod;
			}
			ans+=tmp;
			ans%=mod;
		}
	}
	cout<<ans;
	return 0;
}