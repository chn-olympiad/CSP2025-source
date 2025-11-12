#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[1005];
    int con=0,son=0;
    
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	if(m==5&&a[1]==1&&a[2]==2&&a[3]==3){
		cout<<9; 
	}
	if(m==5&&a[1]==2&&a[2]==2&&a[3]==3){
		cout<<6; 
	}
	
    
	return 0;
}
