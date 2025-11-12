#include<bits/stdc++.h>

using namespace std;

int n,k,a[500099],cnt_of_one=0,cnt_of_zero=0,pre,nozero;
bool f=false,f1;

int main(){
	
  	freopen("xor.in","r",stdin);
 	freopen("xor.out","w",stdout);
	
	cin>>n>>k;f1=false;nozero=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			f=true;nozero--;
		}
		if(f1){
			if(a[i]==pre){
				if(a[i]==0){
					cnt_of_zero++;
				}
				else cnt_of_one++;
			}
			else pre=a[i];
		}
		else pre=a[i];
	}
	
	if(f){
		
		if(k==1){
			
			cout<<nozero+cnt_of_zero;
			
		}
		else if(k==0){
			
			cout<<n-nozero+cnt_of_one;
			
		}
		else cout<<0;
		
	}
	else{
		
		if(k==1){
			
			cout<<n;
			
		}
		else if(k==0){
			
			cout<<cnt_of_one;
			
		}
		else cout<<0;
		
	}
	
	return 0;
	
}