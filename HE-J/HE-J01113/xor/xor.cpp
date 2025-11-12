#include<bits/stdc++.h>
using namespace std;
const int N =5e5+5;
long long n,k,a[N],cnt=0,xor_sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==1){
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			cnt+=x;
		}
		cout<<cnt<<endl;
		return 0;
	}
	if(k==0){
		cout<<n/2<<endl;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==0)xor_sum=a[0];
		else xor_sum = xor_sum xor a[i];
		if(a[i]==k||xor_sum==k)cnt++;
	}
	long long t = xor_sum;
	for(int i=2;i<n;i++){
		for(int j=1;j<n;j+=i){
			xor_sum = xor_sum xor a[j];
			if(xor_sum xor a[j]==k)cnt++;
		}
		xor_sum=t;
	}
	cout<<cnt/k<<endl;
	return 0;
}
