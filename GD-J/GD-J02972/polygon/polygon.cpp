#include<bits/stdc++.h>
using namespace std;
int n,a[7005],ans;
void bl(int k,int js,int mx){
	if(k==(n+1)){
		if(js>(2*mx) && k>=3){
			ans++;
		}
		return ;
	}
	bl(k+1,js,mx);
	bl(k+1,js+a[k],max(mx,a[k]));
}
const int mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=25){
		bl(1,0,0);
		cout<<ans;
	}
	else{
		long long ans=1;
		for(int i=1;i<=n;i++)
			ans=((ans%mod)*2)%mod;
		ans=ans-1-n-(n*(n-1)/2);
		cout<<ans;
	}	
	return 0;
}
