#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
    
	int t;
	cin>>t;
	int n;
	int a[3][t];
	int num=0;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=0;j<3;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=t;i++){
		for(int j=0;j<3;j++){
			if(a[i][j]+a[i-1][j-1]==n/2){
			a[i][j]+a[i-1][j];
		    }
		}
		cout<<num;
	}
	cout<<endl;
    return 0;
}
