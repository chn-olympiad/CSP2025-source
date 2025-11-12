#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=998244353;
bool cmp(ll a,ll b){
	return a<b;
}
ll a[5005],sum=0,num,ans=0;
void dfs(int idx,int f){
	if(idx==0){
		if(sum>num){
			ans++;
			ans%=mod;
			return;
		}
	}
	for(int i=f;i>=1;i--){
		sum+=a[i];
		dfs(idx-1,i-1);
		sum-=a[i];
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=3;i<=n;i++){
		num=a[i]*2;
		for(int j=2;j<i;j++){
			sum=a[i];
			dfs(j,i-1);
		}
	}
	cout<<ans; 
	return 0;
}

