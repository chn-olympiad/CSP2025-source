#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n=0;
	long long k=0;
	cin>>n>>k;
	int sum=0;
	int js=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				sum++;
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			js=js+a[i];
		}
		if(js==n){
			sum=n/2;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					sum++;
				}else{
					if(a[i+1]==1){
						sum++;
						i++;
					}
				}
			}
		}
	}
	cout<<sum;
	return 0;
} 
