#include<bits/stdc++.h>//^
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,max1=0;
	cin>>n>>k;
	long long a[n+1];
	for(long long i=1;i<=n;i++) cin>>a[i];
	for(long long i=1;i<=n;i++){
		long long b[n-i+1];
		for(long long l=1;l<n-i+1;l++) b[i]=0;
		if(a[i]==k){
			if(max1==0){
				max1=1;
			}
		}
		b[1]=a[i];
		for(long long j=i+1;j<=n;j++){
			b[j]=b[j-1]^a[j];
			if(b[j]==k&&max1<j-i){
				max1=j-i;
			}
		}
	}cout<<max1;
	return 0;
}
