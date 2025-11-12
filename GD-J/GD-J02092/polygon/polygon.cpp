#include<iostream>
#include<vector>
using namespace std;
const int mod=998244353;
int n,a[5005];
long long ans;
vector<int>b;
void dfs(int x,int t){
	if(x>3){
		int sum=0,mx=-1;
		for(int i:b)sum+=a[i],mx=max(mx,a[i]);
		if(sum>mx*2)ans=(ans+1)%mod;
	}
	for(int i=t+1;i<=n;i++){
		b.push_back(i);
		dfs(x+1,i);
		b.pop_back();
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=1;
	}
	if(!f){
		for(int i=3;i<=n;i++){
			unsigned long long sum=1;
			for(int j=n;j>n-i;j--)if(j>i)sum*=j;
			for(int j=2;j<=i;j++)if(j<n-i+1)sum/=j;
			ans=(ans+sum)%mod;
		}
		return cout<<ans,0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
