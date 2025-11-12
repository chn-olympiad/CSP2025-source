#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500010]={},ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<n/2;
	}else if(k==1){
		for(int i=0;i<n-1;i++){
			if(a[i]^a[i+1]==1){
				ans++;
				i++;
			}
		}
		cout<<ans;
	}else{
		for(int i=0;i<n-1;i++){
			int sum=a[i];
			while(sum!=k&&i<n){
				i++;
				sum^=a[i];
			}
			if(sum==k){
			    ans++;	
			}
			
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
