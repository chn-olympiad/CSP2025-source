#include<bits/stdc++.h>
using namespace std;
int main(){	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    long long int n,m;
    cin>>n>>m;
    if(m=1)cout<<n*n;
    else{
    	long long int ans=n;
    	for(int i=1;i<n;i++){
    		ans=ans*i;
    		ans=ans%998244353;
		}
	}
	cout<<ans;
	return 0;
} 
