#include<bits/stdc++.h>
using namespace std;
long long n,k,ans=0;
int main() {
//	cin>>n>>k;
//	int a[n+1]={0},b[n+2]={0};
//	for(long long i = 1;i<=n;i++){
//		int fu;
//		cin>>fu;
//		while
//	}
//	b[1]=a[1];
//	for(int i = 2;i<=n;i++){
//		b[i] = xor(b[i-1],a[i]);
//	}
//	for(long long i = 1;i<=n;i++){
//		for(long long j = i;j<=n;j++){
//			if((b[j]-b[i])==k){
//				ans++;
//			}
//		}
//	}
//	cout<<ans;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cout<<k%n; 
	return 0;
}
