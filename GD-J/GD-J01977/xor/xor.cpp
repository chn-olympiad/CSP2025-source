#include <bits/stdc++.h>
//#include <iostream>
//#include <string>
long long n,k,a[500010],ans;
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				ans++;
				
			}
		}
		cout<<ans;
		return 0;
	}else if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
			if(a[i]==k){
				ans++;
				
			}
	}	
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
