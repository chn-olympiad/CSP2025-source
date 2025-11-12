#include<bits/stdc++.h>
using namespace std;
int n,a[500007],k,ans,b[500007];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((b[j]^b[i])==k) {
				i=j-1;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
