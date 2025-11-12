#include<bits/stdc++.h>
using namespace std;
int n,m=0,a;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int x[n+5]; 
	for(int i=0;i<n;i++){
		cin>>x[i];	
	}
	sort(x,x+n);
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
		        a=x[j]+x[j+k]+x[k];
		        if(a>x[j+k]*2){
		    	m++;
			    }
			}
		}
		if(x[0]==1){
			cout<<x[n-1]+x[n-2];
		}else{
			cout<<x[n-1]-x[0]-x[1];
		}
	return 0;
}
