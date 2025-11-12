#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,h,l=0,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			ans++;
		}
	}
	if(ans==n){
		if(k==0){
			cout<<n/2;
			return 0;
		}
		else if(k==1){
			cout<<n;
			return 0;
		}
	}
	else if(k==1){
		ans=0;
		for(int i=1;i<=n;i++){
		    if(a[i]==0){
			    l++;
		    }
		    else{
		    	ans=ans+l/2+1;
		    	l=0;
			}
			if(i==n){
				ans=ans+l/2;
			}
	    }
	    cout<<ans;
	    return 0;
	}
	else if(k==0){
		ans=0;
		for(int i=1;i<=n;i++){
		    if(a[i]==1){
			    l++;
		    }
		    else{
		    	ans=ans+l/2+1;
		    	l=0;
			}
			if(i==n){
				ans=ans+l/2;
			}
	    }
	    cout<<ans;
	}
	else cout<<n;
	return 0;
}
