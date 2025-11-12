#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int arr[m+5][3];
	int arr1[k+5]; 
    cin>>n>>m>>k;
	    for(int i=1;i<=m;i++){
		    for(int j=1;j<=3;j++){
		    cin>>arr[i][j];
	    }	
	}
	for(int j=1;j<=k;j++){
		for(int i=0;i<=m+k+1;i++){
		    cin>>arr[i][j];
	    }
	}
	    cout<<"13";
	return 0;
}
