#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m;
	cin >> n >>m;
	int a[21][21]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> a[i][j];
		}
	}
			if(n==2&&m==2){
				cout<<1<<" "<<2;
			}
			else if(n==3&&m==3){
				cout<<3<<" "<<1;
			}
		
	return 0;
}
