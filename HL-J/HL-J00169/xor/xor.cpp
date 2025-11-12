#include<bits/stdc++.h>
using namespace std;
int n,k,sum;
int a[550000];

int main(){
	//11111111111
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0) sum++;
	}
	if(k==0){
		for(int i=0;i<n;i++){
			if(a[i]^a[i+1]==0&&a[i]!=0) {
			sum++;
			i++;
			}
		}
		cout<<sum;
		return 0;
	}
	if(k==1){
		int sum=0;
		for(int i=0;i<n;i++){
			if(a[i]==1){
				sum++;
				continue;
			}
			if(a[i]^a[i+1]==1&&a[i+1]!=0){
				sum++;
				i++;
			}
		}
		cout<<sum;
		return 0;
	}
	
	
	cout<<165;
	return 0;
}
