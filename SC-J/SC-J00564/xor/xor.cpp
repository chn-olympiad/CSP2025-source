#include<bits/stdc++.h>
using namespace std;
bool f1=1,f2=1;
long long n,a[500010],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f1=0;
		if(a[i]!=1&&a[i]!=0) f2=0;
	}
	if(f1){
		if(k==0) cout<<n/2;
	}
	else if(f2){
		long long ans=0;
		if(k==0){
			for(long long i=1;i<n;i++){
				if(a[i]==a[i+1]){
					ans++;
					i++;
				}
			}
		}
		if(k==1){
			for(long long i=1;i<n;i++){
				if(a[i]!=a[i+1]){
					ans++;
					i++;
				}
				else if(a[i]==a[i+1]&&a[i]==a[i+2]&&a[i]==1){
					ans++;
					i+=2;
				}
			}
		}
		cout<<ans;
	}
	else cout<<n/k+n%k;
	return 0;
}