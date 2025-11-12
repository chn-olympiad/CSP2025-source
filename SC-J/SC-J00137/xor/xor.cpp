#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,sum=0,a[5000];
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			sum=1;
		}
	}
	if(sum==0){
		if(k==0){
			if(n==2){
				cout<<1;
				return 0;
			}else{
				cout<<0;
				return 0;
			}
		}
	}else{
		sum=0;
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					sum++;
				}
			}
			cout<<sum;
			return 0;
		}
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					sum++;continue;
				}
				else if(a[i]-a[i+1]==0&&i<=n-1){
					sum++;
					i++;
				}
			}
			cout<<sum;
		}
	}
	return 0;
} 