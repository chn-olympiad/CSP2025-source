#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	cin>>k;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(sum==n){
		if(n%2==0){
			cout<<n/2;
		}
		else{
			cout<<(n-1)/2;
		}
	}
	else if(sum<n){
		if(k==1){
			cout<<sum;
		}
		if(k==0){
			int ans=0;
			for(int i=1;i<=n-1;i++){
				if(a[i]==1&&a[i+1]==1){
					i++;
					a[i+1]=0;
					ans++;
				}
			}
			cout<<n-sum+ans;
		}
	}
	else{
		cout<<0;
	}
	return 0;
}