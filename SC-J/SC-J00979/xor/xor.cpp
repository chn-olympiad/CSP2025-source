#include<bits/stdc++.h>
using namespace std;
long long n,k,ans=0,a[500005],b[5005][5005]={0};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		b[i][i]=a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(j==1) continue;
			b[i][j]=(b[i][j-1]^a[j]);
		}
	}
	for(long long j=n;j>=1;j--){
		for(long long i=j;i>=1;i--){
			if(b[i][j]==k){
				ans++,j=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}