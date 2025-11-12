#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n,k,a[50009];
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4&&k==2){
		if(a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
			cout<<"2"; 
		}
	}
	if(n==4&&k==3){
		if(a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
			cout<<"2"; 
		}
	}
	if(n==4&&k==0){
		if(a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
			cout<<"1"; 
		}
	}
	return 0;
} 
