#include<bits/stdc++.h>
using namespace std;
const int N=5005,M=998244353;
int n,a[N],maxn,s,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		s+=a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(maxn*2<s) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++){
		int k=1,q=1;
		for(int j=2;j<=i;j++){
			k=j%M*k%M;
		}
		for(int j=n;j>=n-i+1;j--){
			q=j%M*q%M;
		}
		ans=(ans+q/k)%M;
	}
	cout<<ans;
	return 0;
}