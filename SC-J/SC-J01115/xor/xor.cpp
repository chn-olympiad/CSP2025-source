#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k,ans=0;
	cin>>n>>k;
	int num[n+2];
	for(int i=0;i<n;i++)
		cin>>num[i];
	if(k==0){
		cout<<n/2;
		return 0;
	}
	if(k==1){
		for(int i=0;i<n;i++){
			if(num[i]==1) ans++;
		}	
		cout<<ans;
		return 0;
	}
	else{
		cout<<"1";
	}
	return 0;
}