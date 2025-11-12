#include<bits/stdc++.h>
using namespace std;

int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	long long xr=a[1];
	for(int i=2;i<=n;i++){
		if(xr==k){
			ans++;
			xr=a[i]; 
		}
		else{
			xr^=a[i];
		}
	}
	if(xr==k) ans++;
	cout<<ans;
	return 0;
}
