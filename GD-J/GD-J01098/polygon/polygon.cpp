#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,a[5007],b[5007],ans=0;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=a[i]+a[i-1];
	for(int i=3;i<=n;i++){
		for(int r=i-1;r>=2;r--){
			for(int l=r-1;l>=1;l--){
				if(b[r]-b[l-1]>b[i]-b[i-1]){
					ans++;
				}
			}
		}
	}
	cout<<ans%mod<<"\n";
	return 0;
}
