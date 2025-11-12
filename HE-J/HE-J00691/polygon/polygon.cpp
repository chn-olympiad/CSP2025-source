#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],mu,mn=0,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long i=3;i<=n;i++){
		for(long j=1;j<=n-i+1;j++){
			int mu=0,mn=0;
			for(long k=j;k<=j+i-1;k++){
				mu+=a[k];
				if(mn<a[k]) mn=a[k];
			}
			if(mu>mn) ans++;
		}
	}
	cout<<ans%998%244%353;
	return 0;
}
