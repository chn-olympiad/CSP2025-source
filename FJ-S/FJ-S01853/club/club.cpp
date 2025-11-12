#include<iostream>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	int sum=0;
	cin>>t;
	int a[100][100];
	for(int i=0;i<t;i++){
		for(int q=0;q<n;q++){	
		for(int j=0;j<3;j++){
			cin>>a[q][j];
		}
	}cin>>n;
	for(int x=1;x<n;x++){
		for(int b=1;b<3;b++){
		for(int y=1;y<n/2;y++){
			sum+=a[b][n];
		}
		}
		cout<<sum;
		sum=0;
	}
	}
	return 0;
}  
