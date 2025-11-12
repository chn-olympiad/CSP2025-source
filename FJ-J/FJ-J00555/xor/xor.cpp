#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],ans,qz[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qz[i]=qz[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((qz[j]^qz[i-1])==k){
				ans++;
				i=j+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
