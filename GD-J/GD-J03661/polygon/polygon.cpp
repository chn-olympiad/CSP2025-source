#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans,ma;
ll a[5010],num[5000002],cur[5000002];
const ll mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
//	for(ll i=1;i<=n;i++)cout<<a[i]<<" ";
//	cout<<"\n";
	for(ll i=1;i<=n;i++){
		ma+=a[i];
		for(ll j=ma;j>=a[i];j--){
			cur[j]=(num[j]+num[j-a[i]])%mod;
		}
		cur[a[i]]=(cur[a[i]]+1)%mod;
//		for(ll j=0;j<=10010;j++)num[j]=cur[j];
//		if(a[i]==15)cout<<"here\n";
//		for(ll j=1;j<=ma;j++)cout<<j<<" "<<cur[j]-num[j]<<"\n";
//		}
//		cout<<"\n";
		if(i>=3){
			for(ll j=(a[i]*2)+1;j<=ma;j++){
				ans=(ans+cur[j]-num[j])%mod;
//				if(num[j]>0)cout<<j<<" "<<num[j]<<"\n";
			}
//			if(a[i]==15){
//				cout<<"ma ai ans res "<<ma<<" "<<a[i]<<" "<<ans<<" "<<res<<"\n";
//			}
		}
		for(ll i=1;i<=ma;i++)num[i]=cur[i];
//		cout<<"\n";		
	}
	cout<<ans<<"\n";
//	cout<<num[28]<<"\n";
	return 0;
}/*
排序 
遍历每一位做选择木棍中的最大值 ，如果当前是i为，所有木棍只能从1-i位选择
每位最大5000，2倍最大10000
num[i]表示前-位中选择木棍长度和等于i的方案
if(j==a[i]*2)cur[j]=num[j]%mod;
else cur[j]=(num[j-a[i]]+num[j])%mod;
ans[i]=num[a[i]*2+1]; 
num数组正确 
*/
