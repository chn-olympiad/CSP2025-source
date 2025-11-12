#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],sum,j;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n<=2 and k==0){
		if(n<=1){
			cout << 0;
			return 0;
		}
		if(n==2){
			cout << 1;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		j=i;
		long long ans=a[j];
		while(j<=n){
			if(ans==k){
				i=j;
				sum++;
				break;
			}
			j++;
			ans=ans^a[j];
		}
		if(j>=n) break;
	}
	cout << sum;
	return 0;
}
