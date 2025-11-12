#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[100],y,sum=0,o;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	y=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m;j++){
		   if(a[i]<a[j]){
		   	   swap(a[i],a[j]);
		   }
	    }
	}
	for(int i=0;i<n*m;i++){
		if(a[i]==y){
			y=i+1;
			break;
		}
	} 
	y=n*m-y+1;
	if((y-1)%(n*2)>=n){
		cout<<(y-1)/n+1<<" "<<n+1-((y-1)%n+1); 
	}else{
		cout<<(y-1)/n+1<<" "<<(y-1)%n+1; 
	}
	return 0;
} 
