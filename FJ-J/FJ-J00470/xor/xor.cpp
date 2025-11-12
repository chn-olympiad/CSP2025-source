#include<bits/stdc++.h>
using namespace std;
long long n,k,a[600000],num=0;//k[550000],q=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;bool p=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1)num++;
		if(a[i]!=0&&a[i]!=1)p=1;
	}
	if(num==n){
		if(k==1)
		cout<<n;
		else if(k==0){
			cout<<n/2;
		}
		else{
			cout<<0;
		}
	}
	else if(p==0){
		if(k>1)cout<<0;
		else if(k==1){
			cout<<num;
		}
		else if(k==0){//cout<<1;
			long long answer=0;
			for(int i=0;i<n;i++){
				if(a[i]==0){
				answer++;	
				}
				if(a[i]==1&&a[i+1]==1){//cout<<i<<" ";
				answer++;i++;
				}
			}
			cout<<answer;
		}
	}
	else if(p==1){
		long long answer=0,q=0;
		for(int i=0;i<n;i++){
			if(a[i]==k){
			answer++;q=i+1;	
			}
		
		}
		cout<<answer+1;
	}
	return 0;
}
