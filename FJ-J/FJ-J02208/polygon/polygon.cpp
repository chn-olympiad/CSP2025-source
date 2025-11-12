#include<iostream>
#include<algorithm>
using namespace std;
int n;
int a[5010];
int mod=998244353;
int ans=0;
int qm(int d,int z){
	int base=d;
	int sum=1;
	while(z>0){
		if(z&1){
			sum=(sum*base)%mod;
		}
		z=z>>1;
		base=(base*base)%mod;
	}
	return sum;
}
void dfs(int k,int m,int s,int sum){
	if(sum>2*m&&s>=3){
		ans=(ans+qm(2,(n-k)))%mod;
		return ;
	}
	if(k==n){
		return ;
	}
	for(int i=k+1;i<=n;i++){
		dfs(i,max(m,a[i]),s+1,sum+a[i]);
	}
}
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	dfs(0,0,0,0);
	cout<<ans%mod<<endl;
	return 0;
}
