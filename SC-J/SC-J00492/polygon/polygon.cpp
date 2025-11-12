#include<iostream>
#include<cmath> 
#include<cstdio> 
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int n,a[505],maxn=0,tot,l,r;
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
			tot+=a[i];	
		}
		if(tot>2*maxn){
				ans++;
			}
	}
	for(l=1;l<=n-2;l++){
		for(r=l+2;r<=n;r++){
			for(int i=l;i<=r;i++){
				maxn=max(maxn,a[i]);
				tot+=a[i];
			}
			if(tot>maxn*2)ans++;
		}
	}
	cout<<ans%998244353;
	return 0;
}