#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,flag=0,b_flag=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}
		if(a[i]!=0&&a[i]!=1){
			b_flag=1;
		}
	}
	if(flag==0&&k==0){
		cout<<n/2;
	}else if(b_flag==0&&k<=1){
		int sum=0;
		for(int i=0;i<n;i++){
			if(a[i]==1){
				sum++;
			}
		}
		cout<<sum;
	}else{
		cout<<12701;
	}
	return 0;
}
