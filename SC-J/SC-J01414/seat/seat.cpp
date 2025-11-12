#include<bits/stdc++.h>
using namespace std;
int main(){
	//记得干掉注释; 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1001]={0},i,dyx=0;
	cin>>n>>m;
	cin>>a[1];
	for(i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])dyx++;
	}
	int x=dyx%m;
	int y=dyx/m+1;
	if(y%2==0){
		cout<<y<<" "<<m-x;
	}else{
		cout<<y<<" "<<x+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 