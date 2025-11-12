#include<bits/stdc++.h>
using namespace std;
int n,k,a;
bool x=1,y=1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);    
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a;
		if(a==0){
			x=0;
	    }else{
		    if(a>1){
			    y=0;	
			}	
		}
	}
	if(x){
	    cout<<'0';	
	}else{
	    cout<<'1';	
	}
return 0;
}
