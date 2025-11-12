#include<bits/stdc++.h>
using namespace std;
long long n,k,sum,ans,a[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
		}
		long long b=a[i];
		for(int j=i+1;j<=n;j++){
			b^=a[j];
			if(b==k){
				ans++;
			}
		}
	}
	cout<<ans;
return 0;
}
