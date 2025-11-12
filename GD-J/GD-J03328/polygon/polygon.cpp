#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	bool f=true;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    int stick[n],total=0,maxs=0;
	long long ans=0;
    if(n==3){
    	
    	for(int a=0;a<3;a++){
    	cin>>stick[a];	
    	total+=stick[a];
    	maxs=max(maxs,stick[a]);
    
		}
		if(maxs*2<total){
    		cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}else{
		for(int a=0;a<n;a++){
    	cin>>stick[a];	
    	total+=stick[a];
    	maxs=max(maxs,stick[a]);
    	if(stick[a]!=1){
    		f=false;
		}
	}
	if(f){
	if(n>3){
		
		for(int m=3;m<=n;m++){
			int tmp=n,tmp2=m;
			int at=1;
			for(;tmp2>0;tmp--,tmp2--){
				
				at*=(1*tmp)%998244353;
			
				
			}
		
			tmp=m;
			
			for(;tmp>1;tmp--){
		
				at/=(1*tmp)%998244353;
				
				
			}
			ans+=at;
			
		}
		ans%=998244353;
		cout<<ans;
		return 0;
	}
}
	
}
}
