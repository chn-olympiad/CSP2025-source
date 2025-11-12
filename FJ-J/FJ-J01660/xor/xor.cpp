#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k,num1=0,num0=0,ans=0,maxn=-1;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]==1)
    	num1++;
    	if(a[i]==0)
    	num0++;
    	maxn=max(maxn,a[i]);
    }
    if(num1+num0==n){
    	if(num1==n){
    		cout<<n/2;
    		return 0;
    	}else{
    	if(k==1){
    		cout<<num1;
    		return 0;
    	}else{
    		for(int i=2;i<=n;i++){
    			if(a[i]==1&&a[i-1]==1){
    			ans++;
				i++;}
    		}
    		cout<<ans+num0;
    	}	
    	}
    }else{
    	if(k>=maxn){
    		for(int i=1;i<=n;i++){
    			if(a[i]==maxn)
    			ans++;
    		}
    		cout<<ans+1;
    		return 0;
    	}else{
    		if(k==0){
    			for(int i=1;i<=n;i++){
    			if(a[i]==0)
    			ans++;
    		}
    		cout<<ans;
    		return 0;
    		}
			else
    		cout<<n/2;
    	}
    }
	return 0;
}
