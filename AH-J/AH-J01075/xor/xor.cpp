#include<bits/stdc++.h>
using namespace std;
long long a[5000010],n,k,sum[5000010],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}long long l=1,r=1;
	while(l<=r&&r<=n){
		if((sum[r]^sum[l-1])==k){
			l=r+1;
			r++;
			cnt++;
		}else if(a[r]==k){
			l=r+1;
			r++;
			cnt++;
		}else{
			r++;
		}
	}cout<<cnt;
	return 0;
}
