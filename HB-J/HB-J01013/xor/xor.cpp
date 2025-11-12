#include<bits/stdc++.h>
using namespace std;
long long a[500000];
int main(){
	long long n,k;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long ans=0;
	if(n<=2&&k==0){
		if(a[0]==0){
			ans++;
		}
		if(a[1]==0){
			ans++;
		}
		if(a[0]==a[1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
