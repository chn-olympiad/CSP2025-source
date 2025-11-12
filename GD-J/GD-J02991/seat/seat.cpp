#include<bits/stdc++.h> 
using namespace std;
int n,m,sit[100][100],a[1000],R_sit;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	R_sit=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	int lcnt=1,dcnt=1;
	for(int i=n*m;i>=1;i--){
		if(lcnt%2==1){
			if(dcnt<n){
				sit[lcnt][dcnt]=a[i];
				dcnt++;
			}
			else if(dcnt==n){
				sit[lcnt][dcnt]=a[i];
				lcnt++;
				
				
			}
		}
		else if(lcnt%2==0){
			if(dcnt>1){
				sit[lcnt][dcnt]=a[i];
				dcnt--;
			}
			else if(dcnt==1){
				sit[lcnt][dcnt]=a[i];
				lcnt++;
				
				
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(sit[j][i]==R_sit){
				cout<<j<<" "<<i; 
			}
		}
	}
	
}

