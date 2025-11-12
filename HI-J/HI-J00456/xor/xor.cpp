#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500010];
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		int flag=0;
		for(int i=1;i<n;i++){
			if(a[i]==0){
				flag++;
			}
		}
	cout<<flag;
	}
	if(k==1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				sum++;
			}
		}
		cout<<sum;
	}
	if(k>1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				sum++;
			}
			else if(a[i]^a[i+1]==k){
				sum++;
			}
		}
		cout<<sum;
	}
	return 0;
}
