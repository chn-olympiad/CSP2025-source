#include<bits/stdc++.h>
using namespace std;

int n,k,a[500005],l,sum;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	if(a[i]!=1){
    		l=1;
		}
	}
    if(n==1){
    	cout<<0;
    	return 0;
	}
	if(l==0&&k==0){//A
		cout<<n/2;
		return 0;
	}
	if(k==0){
	    for(int i=0;i<n-1;i++){
		    if(a[i]==a[i+1]){
		    	sum++;
		    	i++;
			}
	    }	
	}
	if(k==1){
		for(int i=0;i<n-1;i++){
		    if(a[i]!=a[i+1]){
		    	sum++;
		    	i++;
			}
	    }
	}
	cout<<sum;
    return 0;
}
/*
10 0
1 1 1 1 1 0 0 1 1 0

20 1
1 0 1 0 1 0 0 1 1 0 1 1 1 1 1 0 0 1 1 0
*/


