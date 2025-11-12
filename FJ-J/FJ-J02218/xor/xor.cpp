#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,sum;
	long long ans=0;
	int a[N]={};
	bool f=0;
	cin>>n>>sum;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=1;
		}
	}
	if(f==0){
		cout<<n/2;
		return 0;
	}
	else{
		if(sum==0){
			for(int i=1;i<=n;i++){
				int sum0=0;
				int sum1=0;
				if(a[i]==1)sum1++;
				if(a[i]==0)sum0++;
				if(sum1%2==0&&sum1>=2){
					ans++;
					sum1=0;
					sum0=0;
					continue;
				}	
				else if(sum1==0&&sum0==1){
					ans++;
					sum0=0;
					continue;
				}
			}
			
		}
		if(sum==1){
			for(int i=1;i<=n;i++){
				int sum0=0;
				int sum1=0;
				if(a[i]==1)sum1++;
				if(a[i]==0)sum0++;
				if(sum1%2==1){
					ans++;
					sum1=0;
					sum0=0;
					continue;
				}
				else if(sum0%2==1){
					ans++;
					sum1=0;
					sum0=0;
					continue;
				}	
			}
			
		}
	}
	cout<<ans;
	return 0;
}

