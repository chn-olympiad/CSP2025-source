#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long a[2][2],s,d,z,f,x;
	cin>>f;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cin>>a[i][j];
		}
	}
	x=a[0][0];
	for( int g=0;g<2;g++){
	    for(int h=0;h<2;h++){	
		    if(a[0][0]>a[g][h]){
			    s=a[g][h];
		    }
	    }
	}
	for( int l=0;l<2;l++){
	    for(int k=0;k<2;k++){	
		    if(a[0][0]<=a[l][k]){
			    z=a[l][k];
		    }
	    }
	}
	if(x!=z or s){
		cout<<"2"<<" "<<"1";
	}
//	cout<<"1" <<" "<<"1" ;
	return 0;
}

