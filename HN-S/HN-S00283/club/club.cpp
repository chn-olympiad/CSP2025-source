#include<iostream>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,s=0,c=0;
	cin>>n;
	int a;
	cin>>a;
	int x[1][a];
	for(int j=0;j<=a;j++){
		cin>>x[j][j];
	}
	if(x[0][0]<x[0][1]){
		s=x[0][1];
	}
	else if(x[0][0]>x[0][1]){
		s=x[0][0];
	}
	c+=s;
	cout<<c<<endl;
	return 0;
}
