#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    if(n<=3){
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=n;j++){
    			for(int x=1;x<=n;x++){
    				if(a[i]+a[i]+a[i]>2*a[n]){
    					ans++;
					}
				}
			}
		}	
	}
	cout<<ans;
	
	return 0;
}