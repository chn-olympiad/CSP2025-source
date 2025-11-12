#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],sum,flag,flag1,temp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}if(a[i]!=1&&a[i]!=0){
			flag1=1;
		}
	}if(flag==0){
		cout<<n/2;
	}else if(flag1==0){
		if(k==0){
			for(int i=0;i<n;i++){
				if(a[i]==0){
					sum++;
				}else if(a[i]==a[i+1]){
					sum++;
					i=i+1;
				} 
			}
		}else{
			for(int i=0;i<n;i++){
				if(a[i]==1){
					sum++;
				}
			}
		}cout<<sum;
	}
	return 0;
}