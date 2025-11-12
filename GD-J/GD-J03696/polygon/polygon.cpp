#include <iostream>
using namespace std;
int main(){
	int n,a[11],m;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i+j>k||i+k>j||j+k>i&&i!=j&&i!=k&&j!=k){
					m++;
				}
			}
		}
	}
	cout<<m/14+n;
}

