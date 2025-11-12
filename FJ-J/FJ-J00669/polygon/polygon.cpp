#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.in","w",stdout);
    long long n,a[5005],s[5005],ans=0;
    cin>>n;
    s[0]=1;
    for(int i=1;i<=n;i++){
   	   cin>>a[i];
   	   s[i]=i*s[i-1];
    }
    for(int i=n;i>=3;i--){
    	for(int j=i-1;j>=2;j--){
    		for(int k=j-1;k>=i-j;k--){
    			if(a[j]+a[k]>a[i]){
    				ans+=1;
				}
				if(a[j]+a[k]>=a[i]){
    				for(int l=1;l<=k-1;l++){
    					ans+=s[k-1]/s[l-1]/s[l];
					}
				}
			} 
		}
	} 
	cout<<ans;
}
