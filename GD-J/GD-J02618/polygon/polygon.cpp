#include<bits/stdc++.h>
using namespace std;
long long mod=998244353,n,ans=0,z=0;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3) cout<<1;
	else{
		for(int i=n-3;i>0;i--)ans+=i;
		cout<<ans;
	}
	return 0;
}
