#include<bits/stdc++.h>
using namespace std;
int a[100010][10];
int main(){
	freopen("replace4.in","r",stdout)
	freopen("replace4.out","w",stdout)
	int t,n,num=0;
	cin>>t>>n;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=3;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=3;j++){
			if(a[i][j]>a[i][j-1]){
				num==a[i][j];
			}
		}
	}
	cout<<num;
	
	
	
	
	return 0;
}
