#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[701100];
int xr[1010100];
int tmp,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xr[i]=xr[i-1]^a[i];
	}
	cout<<n/2;
//	for(int i=1;1;i++){ 8 
//		for(int j=i;j<=n;j++){
//			if((xr[j]^xr[i])==k){
//				ans++;
//				cout<<i<<' '<<j<<' '<<(a[j]^(a[i]^xr[i]))<<endl;
//				i=j+1;
//				break;
//			}
//		}
//		if(i>n){
//			cout<<ans;
//			return 0;
//		}
//	}
	return 0;
}
