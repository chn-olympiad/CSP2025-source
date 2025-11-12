#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005],maxx=0,h=0;
	long long ans=0,mod=998244353;
	cin>>n;
	if(n<3){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<0;
		return 0;
	}
	else if(n==3){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			h+=a[i];
			maxx=max(maxx,a[i]);
		}
		if(h>2*maxx){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=i-2;j++){
			h=0;
			maxx=0;
			for(int k=j;k<=i;k++){
				h+=a[k];
				maxx=max(maxx,a[k]);
 			}
    		if(h>2*maxx){
    			ans=(ans+1)%mod;
    		}
		}
	}
	printf("%lld",ans);
	return 0;
}
