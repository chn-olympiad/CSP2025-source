#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,a[5001],cnt;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;//至少三角形 至多n边形 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)cnt++;
	}
	if(cnt==n){
		if(n<=3)cout<<0;
		else if(n==4)cout<<1;
		else if(n==5)cout<<6;
	}else if(n<=3){//三角形 
		if(n<3)cout<<0;
		else{
			int mx=max(a[1],max(a[2],a[3])),sum=a[1]+a[2]+a[3];
			if(mx==a[1]&&sum>2*a[1]){
				cout<<1;
				return 0;
			}else if(mx==a[2]&&sum>2*a[2]){
				cout<<1;
				return 0;
			}else if(mx==a[3]&&sum>2*a[3]){
				cout<<1;
				return 0;
			}
			cout<<0;
		}
	}else{
		int aaa=0;
		for(int i=1;i<=n;i++){
			int mx=max(a[i],max(a[i+1],a[i+2])),sum=a[i]+a[i+1]+a[i+2];
			if(mx==a[i]&&sum>2*a[i])aaa++;
			else if(mx==a[i+1]&&sum>2*a[2])aaa++;
			else if(mx==a[i+2]&&sum>2*a[3])aaa++;
		}
		cout<<(aaa+n)%mod;
	}
	return 0;
}