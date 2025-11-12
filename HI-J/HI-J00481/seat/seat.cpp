#include <bits/stdc++.h>
using namespace std;
int n,n1=1,m,m1=1,k,l;
int main(){
	freopen("seat.in","r",stdin);	
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    int j=m*n,p=1;
    cin>>k;
    for(int i=1;i<j;i++){
    	cin>>l;
    	if(l>k){
    		if(p==1){
    			if(m1==m){
    				n1++;
    				p=0;
				}else{
					m1++;
				}
			}else{
				if(m1==1){
    				n1++;
    				p=1;
				}else{
					m1--;
				}
			} 
		}	
	}
	cout<<n1<<" "<<m1;
	return 0;
}

