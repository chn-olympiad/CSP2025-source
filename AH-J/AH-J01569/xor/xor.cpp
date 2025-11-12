#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f=1;
	int sum=0; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=0;
		}
		if(a[i]==0){
			sum++;
		}
	}
	if(k==0&&f){
		cout<<n/2;
	}else{
		cout<<sum+(n-sum)/2;
	}
	if(k==1){
		cout<<n-sum;
	}
}
