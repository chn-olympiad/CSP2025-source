#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	unsigned long long k;
	cin>>n>>k;
	vector<long long> a,sum;
	for(int i=0;i<n;i++){
		unsigned long long x;
		cin>>x;
		a.push_back(x);
		if(i==0){
			sum.push_back(x);
			continue;
		}
		sum.push_back(sum[i-1]^x);
	}
	int f=0;
	for(int i=n;i>=1;i--){
		for(int j=n-1;j-i+1>=0;j--){
			if(abs(sum[j]-sum[j-i])==k){
				cout<<i;
				f=1;
				break;
			}
		}
		if(f==1){
			break;
		}
	}
	return 0;
}
