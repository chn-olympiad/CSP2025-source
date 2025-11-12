#include<bits/stdc++.h>
using namespace std;
int n,ans,l,r,ma=0,he=0;
int a[5005];//long

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=3;i<=n;i++){
		for(int j=1;j<=i;j++){
			l=j;
			r=i+j-1;
			if(r<=n){
				for(int k=j;k<=r;k++){	
				   if(a[k]>ma){
			           ma=a[k];
		           }
		           he=he+a[k];
			    }
			    
				if(he>ma*2){
			   	  ans++;
			    }
			}
			he=0;
			ma=0;   
		}
	}
	ans=ans%998;
	ans=ans%244;
	ans=ans%353;
	cout<<ans;
	return 0;
}
