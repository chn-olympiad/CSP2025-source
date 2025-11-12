#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],mx=-1,sum;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if (n==3){
		cin>>a[1]>>a[2]>>a[3];
		if (a[1]+a[2]+a[3]>2*(max(a[1],max(a[2],a[3])))){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	for (int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
	}
	if (mx==1){
		int x=2;
		for (int i=3;i<=n;i++){
			int y=1;
			for (int j=n;j>=n-i+1;j--){
				y=y*j;
			}
			x*=i;
			y=y/x;
			y=y%998244353;
			sum+=y;
			sum%=998244353;	
		}
		cout<<sum;
		return 0;
	}
	return 0;
} 