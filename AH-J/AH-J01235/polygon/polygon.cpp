#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],s[5005],maxn,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		maxn=max(maxn,a[i]);
	}
	if(n==3){
		if(s[n]>maxn*2) cout<<1;
		else cout<<0;
		return 0;
	}
	return 0;
}
