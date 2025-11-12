#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
int flag,flagg;
long long a[5000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}else if(a[i]>1){
			flagg=1;
		}
	}
	if(flag==0 && k==1){
		ans=n;
	}else if(flagg==0 && k==1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				sum++;
			}
		}
		ans=sum;
	}else if(flagg==0 && k==0){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				sum++;
			}
		}
		ans=sum;
	}
	cout<<ans;
	return 0;
} 
