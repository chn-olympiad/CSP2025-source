#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],sum[500010],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			sum[i]=a[i];
		}else{
			sum[i]=sum[i-1]^a[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(sum[i]==k){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
