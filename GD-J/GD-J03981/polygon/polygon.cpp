#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int mod=998244353;
int a[1000005],tree[1000005];
int vis[100005];
int fpow(int a,int b){
	int ans=1,pose=a;
	while(b>0){
		if(b%2==1) ans*=pose%mod;
		ans%=mod;
		pose*=pose;
		pose%=mod;
		b/=2;
	}
	return ans;
}
int nex(int x){
	return x&(-x);
}
int tr_sum(int n){
	int ans=0;
	for(int i=n;i>0;i-=nex(i)){
		ans+=tree[i]%mod;
		ans%=mod;
	}
	return ans;
}
void tr_add(int i,int num){
	if(num==0) return ;
	for(int j=i;j<=10000;j+=nex(j)){
		tree[j]+=num%mod;
		tree[j]%=mod;
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	vis[a[1]+a[2]]++;
	vis[a[1]]++;
	vis[a[2]]++;
	tr_add(a[1]+a[2],1);
	for(int i=3;i<=n;i++){
		ans+=(fpow(2,i-1)%mod-(i-1)-1-tr_sum(a[i])%mod+mod)%mod;
		//cout<<ans<<"\n";
		for(int j=a[n]-a[i];j>=1;j--){
//			if(sum[j]>0){
//				vis[j+a[i]]+=vis[j];
//				tr_add(j+a[i],sum[j]);
//				cout<<j<<" "<<a[i]<<" "<<j+a[i]<<" "<<1<<"\n";
//			}
			vis[j+a[i]]+=vis[j]%mod;
			vis[j+a[i]]%=mod;
			tr_add(j+a[i],vis[j]);
			//cout<<j<<" "<<a[i]<<" "<<j+a[i]<<" "<<vis[j]<<"\n";
		}
		vis[a[i]]++;
	}
	cout<<ans%mod;
	return 0;
}
