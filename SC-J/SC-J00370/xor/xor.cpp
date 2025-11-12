#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],b[500005],c[500005],ans; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	for(int i=1;i<=n;i++){
	 	for(int j=1;j<=i;j++){
	 		if(b[i]^b[j]==k){
	 			ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}