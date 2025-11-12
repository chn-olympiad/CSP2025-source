#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
int n,a[100010],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]+a[k]>min(min(a[i],a[j]),a[k])*2){
					ans++;
					ans%=mod;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}