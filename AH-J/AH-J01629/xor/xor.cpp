#include<bits/stdc++.h>
using namespace std;
long long a[510000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,cc=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cc++;
		}
	}
	if(k==0&&cc==n){
		if(n%2==1){
			cout<<0;
		}else{
			cout<<n/2;
		}
	}else{
		long long sum=-11111,cnt=0;
		for(int i=1;i<=n;i++){
			if(sum==-11111){
				sum=a[i];
			}else{
				sum=sum^a[i];
			}
			if(sum==k){
				cnt++;
				sum=-11111;
			}
		}
		if(sum==k){
			cnt++;
		}
		cout<<cnt;
	}
	return 0;
}
