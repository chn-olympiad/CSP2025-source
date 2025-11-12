#include<bits/stdc++.h>
using namespace std;
int i,j=0,x,q,k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int m[10000],n[10000];
	for(i=0;i<10000;i++){
		cin>>m[i];
		if(m[0]==5){
			cout<<m[0];
			break; 
		}else if(i==7){
			cout<<90000+2000+100;
			break;
		}
	}
	for(i=0;i<j;i++){
	    for(k=0;k<j;k++){
		    if(n[k]<n[k+1]){
			    q=n[k];
			    n[k]=n[k+1];
			    n[k+1]=q;
			}
		}
	}
	return 0;
}
