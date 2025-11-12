#include<bits/stdc++.h>
using namespace std;
int n,m,z;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}	
	z=a[1];
	sort(a+1,a+n*m+1);
	int k=n*m;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[k]==z){
					cout<<i<<" "<<j;
					return 0;
				}
				k--;
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[k]==z){
					cout<<i<<" "<<j;
					return 0;
				}
				k--;
			}
		}
	}
	return 0;
	//3 3
    //94 95 96 97 98 99 100 93 92
} 