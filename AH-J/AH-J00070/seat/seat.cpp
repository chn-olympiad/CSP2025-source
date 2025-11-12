#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int arr[200]={};
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
		cin>>arr[i];
    }
    int x=0,a=arr[0];
    sort(arr,arr+n*m,cmp);
    for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(arr[x++]==a){
				cout<<i+1<<" "<<j+1;
				break;
		    }
	    }
	}
    return 0;
}
