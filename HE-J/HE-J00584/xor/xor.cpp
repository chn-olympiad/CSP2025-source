#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,sum;
long long a[500005];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long l=1,r=n;
	while(l<=r){
		if(a[l]==k){
			ans++;
			l++;
			sum=0;
		}
		else{
			sum^=a[l];
			if(sum==k) ans++,sum=0;
			l++;
		} 
	}
	cout<<ans;
	return 0;
}
