#include<bits/stdc++.h>
using namespace std;

long long n,k,a[200005],sum0,sum1;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!a[i])sum0++;
		if(a[i]==1)sum1++;
	}
	if(k==0&&sum1==n){
		cout<<n/2;
	}
	else if(k<=1 && sum0+sum1==n){
		if(k==0){
			for(int i=1;i<n;i++){
				if(a[i]==a[i+1]&&a[i]==1){
					sum0++,i++;
				}
			}
			cout<<sum0;
		}
		if(k==1){
			for(int i=1;i<n;i++){
				if(a[i]==a[i+1] && a[i]==0){
					sum1++,i++;
				}
			}
			cout<<sum1;
		}
	}
	
	return 0;
}
