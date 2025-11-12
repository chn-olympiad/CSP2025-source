#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,num[500005],sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	int flag=0,flag2=0;
	for(int i=1;i<=n;i++){
		if(num[i]!=1){
			flag=1;
		}
		if(num[i]!=0){
			flag2=1;
		}
	}
	if(k==0&&flag==0){
		if(n<=2){
			if(n==1) sum=0;
			if(n==2) sum=1;
		}else{
			sum=n/2;
		}	
	}else if(k==1&&(flag==0||flag2==0)){
		for(int i=1;i<=n;i++){
			if(num[i]==1){
				sum++;
			}
		}
	}else if(k==0&&(flag==0||flag2==0)){
		for(int i=1;i<=n;i++){
			if(num[i]==0){
				sum++;
			}
			if(num[i]==1&&num[i+1]==1){
				sum++;
				i++;
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			if(num[i]==k){
				sum++;
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
