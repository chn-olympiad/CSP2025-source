#include<bits/stdc++.h>
using namespace std;
int main(){
	reopen("club.in","r"stdin)
	reopen("club.out","w"stdon)
	int t,n;
	int a[100][100];	
	cin>>t;
	for(int i=0;i<=t;i++){
		cin>>n;
		for(int j=0;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<=t;i++){
		for(int j=0;j<=t;j++){
			cout<<a[i][j]<<" ";			
		}
	}
	
	return 0;
}
