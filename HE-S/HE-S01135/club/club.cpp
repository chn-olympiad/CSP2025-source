#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	int arr[n+5][3];
    cin>>n;
	    for(int i=1;i<=n;i++){
		    for(int j=1;j<=3;j++){
		    cin>>arr[i][j];
	    }	
	}
    for(int i=1;i<=n;i++){
    	for(int j=1;j<3;j++){
    		if(arr[i][j]<=arr[i][j+1]){
    			int m=arr[i][j];
    			arr[i][j]=arr[i][j+1];
    			arr[i][j+1]=m;
		    }
		}
	}
    for(int i=1;i<=n;i++){
	    for(int j=1;j<=3;j++){
		    cout<<arr[i][j]<<" ";
	    }	
	    cout<<endl;
	}

	return 0;
} 

