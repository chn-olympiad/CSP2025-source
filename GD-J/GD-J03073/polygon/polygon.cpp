#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,a[5010],sum[5010],ans,flag;
void dfs(int x,int sum,int Max){
	if(x>n){
		if(sum>Max*2){
			ans++;
		}
		return ;
	}
	dfs(x+1,sum,Max);
	dfs(x+1,sum+a[x],(Max<a[x]?a[x]:Max));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=1;
	}
	sort(a+1,a+n+1);
	if(!flag){
		for(int i=3;i<=n;i++){
			long long sum=1;
			for(int j=n;j>=n-i+1;j--){
				sum*=j;
			}
			for(int j=1;j<=i;j++){
				sum/=j;
			}
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,1);
	cout<<ans;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
