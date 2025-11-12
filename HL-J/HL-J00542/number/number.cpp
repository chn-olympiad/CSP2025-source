#include<bits/stdc++.h>
#include<fstream>
using namespace std;
string s[1001];
int main(){

	int n,m,x,y,z,t,w,a[1001][1001];
	ifstream("number.in");
	ofstream("number.out");
	cin>>x>>y>>z;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=x*y;i++){
		for(int j=1;j<=x*y;j++){
			if(a[i][j]<a[i+1][j]){
				a[i][j+1]=z;
				a[i][j+1]=a[i][j];
				a[i][j]=z;
			}
		
		}
	}
	for(int i=1;i<=x*y;i++){
		if(a[i]){
			t==w;
			t==1;
			break;
		}
	}
	
	return 0;
}