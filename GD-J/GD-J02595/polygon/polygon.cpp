#include<bits/stdc++.h>
using namespace std;
long long n,a[100],sum,ma=0,ans=3;
int main()
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		ma=max(a[i],ma);
		if(i>4){
			ans+=i-2;
			ans=ans% 998244353;
		}
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		cout<<1;
		return 0;
	}
	cout<<ans;
	return 0; 
}
