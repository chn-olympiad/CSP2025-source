#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005];
	cin>>n;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxn) maxn=a[i];
	}
	if(n<=3){
		if(n==1)cout<<0;
		if(n==2)cout<<0;
		if(n==3){
			if(a[1]+a[2]+a[3]>2*maxn) cout<<1;
			else cout<<0;
		}
	}
	else if(maxn==1){
		long long sum=0;
		for(int i=3;i<=n;i++){
			long long x=1,y=1,z=1;
			for(int j=1;j<=n;j++){
				x*=j;
			}
			for(int j=1;j<=i;j++){
				y*=j;
			}
			for(int j=1;j<=n-i;j++){
				z*=j;
			}
			sum+=(x/y/z);
		}
		cout<<sum%998244353;
	}
	return 0;
} 
