#include <bits/stdc++.h>
using namespace std;
const int N=5e3+5;
const int mod=998244353;
int n,a[N];
long long ans;
bool flag=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			flag=1;
			break;
		}
	}
	if(!flag){
		for(int i=3;i<=n;i++){
			long long x=1,y=1;
			for(int j=n-i+1;j<=n;j++)x*=j;
			for(int j=1;j<=i;j++)y*=j;
			ans+=((x/y)%mod);
		}
	}
	ans%=mod;
	cout<<ans;
	return 0;
}
