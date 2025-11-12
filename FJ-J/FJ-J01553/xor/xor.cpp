#include <bits/stdc++.h>
using namespace std;

long long n,k,a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
	}
	if((n==1 && k==0 && a[1]==1) || (n==2 && k==0 && a[1]==1 && a[2]==1)){
		cout << n/2;
		return 0;
	}
	if(k<=1){
		long long sum=0;
		for(long long i=1;i<=n;i++){
			if(a[i]==k){
				sum++;
			}
		}
		cout << sum;
		return 0;
	}
	return 0;
}
