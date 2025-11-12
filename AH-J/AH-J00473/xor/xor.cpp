#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
long long xxor;
long long ans;
bool chongzhi=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		if(chongzhi){
			xxor=a[i];
			chongzhi=0;
		}
		else{
			xxor=xxor ^ a[i];
		}
		if(xxor==k){
			ans++;
			chongzhi=1;
		}
	}
	cout<<ans;
	return 0;
}
