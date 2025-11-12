#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	int n,k;
	cin>>n>>k;
	int a[n];
	int qqq=1;
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0){
			qqq=0;
		}
	}
	if(qqq=1){
		cout<<n/2;
		return 0;
	}else{
		
		int s=a[0];
		for(int i=1;i<n;i++){
			if(k==0){
				if(s+a[i]==1){
					s=1;
				}else{
					s=a[i+1];
					i++;
					ans++;
				}
			}else{
				if(s+a[i]==1){
					s=a[i+1];
					i++;
					ans++;
				}else{
					s=0;
				}
			}
		}
	}

	
	cout<<ans;
	
	return 0;
}
