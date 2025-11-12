#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005],q[500005];
long long ans=0;
long long r=500005;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q[i]=a[i]^q[i-1];
	}
	for(int i=1;i<=n;i++){
		if(ans==0){
			for(int j=i;j<=n;j++){
				if((q[j]^q[i-1])==k){
					ans++;
					r=j;
					break;
				}
			}
		}
		else{
			if(i<=r){
				for(int j=i;j<=r;j++){
					if((q[j]^q[i-1])==k){
						r=j;
						break;
					}
				}
			}
			else{
				for(int j=i;j<=n;j++){
					if((q[j]^q[i-1])==k){
						ans++;
						r=j;
						break;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
