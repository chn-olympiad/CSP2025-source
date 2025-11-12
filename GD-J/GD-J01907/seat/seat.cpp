#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ccbl[n*m];
	for(int i=0;i<n*m;i++){
		cin>>ccbl[i];
	}
	int xRc=ccbl[0];
	int xRs;
	sort(ccbl,ccbl+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(ccbl[i]==xRc){
			xRs=i+1;
			break;
		} 
	}
	//cout<<"xRc:"<<xRc<<" xRs:"<<xRs<<endl;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if((i-1)*n+j==xRs){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(i*n+1-j==xRs){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}	
	}
	return 0;
} 
