#include<bits/stdc++.h>
using namespace std;
unsigned long long a[1000000];
unsigned long long n,k;
int main(){	
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
	cin>>n>>k;
	unsigned long long ans=0;	
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}	
	if(k==0){	
	int f=1;	
	for(long long i=1;i<=n;i++){
		if(a[i]==0)f=0;
	}	
	if(f==1){
		cout<<n/2;
		return 0;
	}else{
		for(long long i=1;i<=n;i++){
			if(a[i]==0)ans++;
			else if(a[i]==1&&i!=1){
				if(a[i-1]==1){
					ans++;
					a[i]=0;
					a[i-1]=0;
				}else{
					continue;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	}else if(k==1){
		for(long long i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
