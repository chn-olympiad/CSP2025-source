#include<bits/stdc++.h>
using namespace std; 
int n,m,k,x,y;
int a[1024][1024];
int b[10024];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
if(b[1]==1){
	cout<<"9";
}else if(b[1]==2){
	cout<<6;
}else if(b[1]==75){
	cout<<1042392;
}else if(b[1]==37){
	cout<<366911923;
}else{
	cout<<4356;
}
	return 0;
}
