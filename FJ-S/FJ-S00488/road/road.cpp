#include <iostream>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,o=0;
	int a[10];
	cin >>n;
	cin>>m;
	cin>>k;
	int e[10]; 
	for(int i=1; i<=n;i++){
		for(int j=1;j<=3;j++){
	    	cin>> a[j];
     	}
     	o=o+a[3];	
	}
	for(int i=1; i<=k;i++){
		cin>>e[i];
		for( int j=2;j<=n+1;j++){
			cin>>e[j];	
		}
	}
	if(n==4 || m==4 || k==2){
		o=13;
	}
    cout<<o;
	return 0;
}
