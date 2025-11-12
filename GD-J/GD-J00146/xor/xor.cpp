#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long n,k,a[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool vis=1;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) vis=0;
	}
	if(vis){
		ans=0;
		cout<<n/2;
	}else{
		ans=0;
		if(k==0){
			for(long long i=1;i<=n;i++){
				if(a[i]==a[i+1]&&a[i]==1){
					ans++;
					i++;
				}
				if(a[i]==0){
					ans++;
				}
			}
			cout<<ans;
		}else{
			for(long long i=1;i<=n;i++){
				if(a[i]==a[i+1]&&a[i]==0){
					ans++;
					i++;
				}
				if(a[i]==1){
					ans++;
				}
			}
			cout<<ans;
		}
	}
	return 0;
}
